#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const long long MOD = 998244353;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> C(n);
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }
  vector<long long> inv(n);
  inv[1] = 1;
  for (int i = 2; i < n; i++) {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<vector<vector<i64>>> dp(4,
                                 vector<vector<i64>>(k + 1, vector<i64>(n, 0)));
  dp[0][0][0] = 2;
  dp[1][0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      i64 p = inv[E[j].size()];
      for (int k = 0; k <= 3; k++) {
        for(int l: E[j]){
          dp[k][i+1][l] += dp[k][i][j]*p;
          dp[k][i+1][l]%=MOD;
          if(C[l] ==0&& k<2 || C[l]==1&&k==2){
            dp[k+1][i+1][l]+=dp[k][i][j]*p;
            dp[k+1][i+1][l]%=MOD;
          }
        }
      }
    }
  }
  i64 ans =0;
  for(int i=0;i<n;i++){
    ans+=dp[3][k][i];
  }
  ans%=MOD;
  cout<<ans<<endl;
}
