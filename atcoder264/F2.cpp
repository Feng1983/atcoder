#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int H, W;
  cin >> H >> W;
  vector<int> R(H);
  for (int i = 0; i < H; i++){
    cin >> R[i];
  }
  vector<int> C(W);
  for (int i = 0; i < W; i++){
    cin >> C[i];
  }
  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      char c;
      cin >> c;
      A[i][j] = c - '0';
    }
  }
  vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(H, vector<long long>(W, INF)));
  dp[0][0][0] = 0;
  dp[1][0][0] = R[0];
  dp[2][0][0] = C[0];
  dp[3][0][0] = R[0] + C[0];
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      for (int k = 0; k < 4; k++){
        if (i < H - 1){
          int k2 = k;
          if (A[i][j] != A[i + 1][j]){
            k2 ^= 1;
          }
          if ((k2 & 1) == 1){
            dp[k2][i + 1][j] = min(dp[k2][i + 1][j], dp[k][i][j] + R[i + 1]);
          } else {
            dp[k2][i + 1][j] = min(dp[k2][i + 1][j], dp[k][i][j]);
          }
        }
        if (j < W - 1){
          int k2 = k;
          if (A[i][j] != A[i][j + 1]){
            k2 ^= 2;
          }
          if ((k2 >> 1 & 1) == 1){
            dp[k2][i][j + 1] = min(dp[k2][i][j + 1], dp[k][i][j] + C[j + 1]);
          } else {
            dp[k2][i][j + 1] = min(dp[k2][i][j + 1], dp[k][i][j]);
          }
        }
      }
    }
  }
  long long ans = INF;
  for (int i = 0; i < 4; i++){
    ans = min(ans, dp[i][H - 1][W - 1]);
  }
  cout << ans << endl;
}
