#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MOD = 998244353;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<i64> inv(m + 1);
  inv[1] = 1;
  for (int i = 2; i <= m; i++) {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<vector<i64>> dp(k + 1, vector<i64>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 1; k <= m; k++) {
        int j2 = j + k;
        if (j2 > n) {
          j2 = n * 2 - j2;
        }
        dp[i + 1][j2] += dp[i][j] * inv[m];
        dp[i + 1][j2] %= MOD;
      }
    }
    dp[i + 1][n] += dp[i][n];
    dp[i + 1][n] %= MOD;
  }
  cout << dp[k][n] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
