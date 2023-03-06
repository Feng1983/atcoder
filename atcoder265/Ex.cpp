#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const long long HALF = 499122177;

vector<long long> operator+(vector<long long> A, vector<long long> B) {
  int N = A.size();
  for (int i = 0; i < N; i++) {
    A[i] += B[i];
    A[i] %= MOD;
  }
  return A;
}
vector<long long> operator-(vector<long long> A, vector<long long> B) {
  int N = A.size();
  for (int i = 0; i < N; i++) {
    A[i] += MOD - B[i];
    A[i] %= MOD;
  }
  return A;
}
vector<long long> half(vector<long long> A) {
  int N = A.size();
  for (int i = 0; i < N; i++) {
    A[i] *= HALF;
    A[i] %= MOD;
  }
  return A;
}
void fwt(vector<vector<long long>> &A, bool inv) {
  int N = A.size();
  for (int i = 1; i < N; i <<= 1) {
    for (int j = 0; j < N; j++) {
      if ((j & i) == 0) {
        vector<long long> x = A[i];
        vector<long long> y = A[i | j];
        A[j] = x + y;
        A[j | i] = x - y;
        if (inv) {
          A[j] = half(A[j]);
          A[j | i] = half(A[j | i]);
        }
      }
    }
  }
}
vector<vector<long long>> operator*(vector<vector<long long>> A,
                                    vector<vector<long long>> B) {
  int N = A[0].size();
  int M = B[0].size();
  fwt(A, false);
  fwt(B, false);
  vector<vector<long long>> C(32, vector<long long>(N + M - 1, 0));
  for (int i = 0; i < 32; i++) {
    C[i] = atcoder::convolution(A[i], B[i]);
  }
  fwt(C, true);
  return C;
}

int main() {

  int H, W;
  cin >> H >> W;
  vector<vector<long long>> F(32, vector<long long>(61, 0));
  for (int i = 0; i < W; i++) {
    for (int j = i + 1; j < W; j++) {
      int c = i - (W - 1 - j) + 30;
      F[0][c]++;
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < i; j++) {
      F[i - j - 1][30]++;
    }
  }
  int H2 = H;
  vector<vector<long long>> G(32, vector<long long>(1, 0));
  G[0][0] = 1;
  while (H > 0) {
    if (H % 2 == 1) {
      G=G*F;
    }
    H/=2;
    if(H==0){
      break;
    }
    F=F*F;
  }
  long long ans=0;
  for(int i=0;i<32;i++){
    for(int j = 0;j<=60*H2;j++){
      int j2= j-30*H2;
      if(i == 0 && j2>0 || i>0 &&j2>=0){
        ans+=G[i][j];
      }
    }
  }
  ans%=MOD;
  cout<<ans<<endl;
  return 0;
}
