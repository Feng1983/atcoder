#include <bits/stdc++.h>
#include <ios>
using namespace std;
const long long MOD = 998244353;

long long modpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a) { return modpow(a, MOD - 2); }

vector<vector<long long>> matmul(vector<vector<long long>>A,
vector<vector<long long>>B){ int N= A.size(); vector<vector<long long>>
ans(N,vector<long long>(N,0)); for(int i=0;i<N;i++){ for(int j =0; j<N;j++){
      for(int k  =0;k<N;k++){
        ans[i][k] +=A[i][j]*B[j][k];
        ans[i][k] %=MOD;
      }
    }
  }
  return ans;
}


vector<vector<long long>> matexp(vector<vector<long long>> A, long long b) {
  int N = A.size();
  vector<vector<long long>> ans(N, vector<long long>(N, 0));
  for (int i = 0; i < N; i++) {
    ans[i][i] = 1;
  }
  while (b > 0) {
    if (b % 2 == 1) {
      ans = matmul(ans, A);
    }
    A = matmul(A, A);
    b /= 2;
  }
  return ans;
}
void solve() {
  long long n, x, y;
  cin >> n >> x >> y;
  string c;

  cin >> c;
  x = x * modinv(100) % MOD;
  y = y * modinv(100) % MOD;
  cout << x << " , y " << y << endl;
  long long P = 1;
  for (int i = 0; i < 24; i++) {
    if (c[i] == 'T') {
      P *= (MOD + 1 - x);
      P %= MOD;
    }
    if (c[i] == 'A') {
      P *= (MOD + 1 - y);
      P %= MOD;
    }
  }
  P = MOD + 1 - P;
  P %= MOD;
  P = modinv(P);

  vector<vector<long long>> A(24, vector<long long>(24, 0));
  for (int i = 0; i < 24; i++) {
    long long cp = 1;
    for (int j = 1; j <= 24; j++) {
      int t = (i + j) % 24;
      if (c[t] == 'T') {
        A[i][t] = cp * x % MOD * P % MOD;
        cp *= MOD + 1 - x;
        cp %= MOD;
      }
      if (c[t] == 'A') {
        A[i][t] = cp * y % MOD * P % MOD;
        cp *= MOD + 1 - y;
        cp %= MOD;
      }
    }
  }
  A = matexp(A, n);

  long long ans = 0;
  for (int i = 0; i < 24; i++) {
    if (c[i] == 'A') {
      ans += A[23][i];
    }
  }
  ans %= MOD;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
