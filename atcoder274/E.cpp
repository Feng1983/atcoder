#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

const double INF = 1000000000000000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int n, m;
  cin >> n >> m;
  vector<int> X(n + m), Y(n + m);
  for (int i = 0; i < n + m; i++) {
    cin >> X[i] >> Y[i];
  }
  vector<vector<double>> d(n + m, vector<double>(m + n));
  for (int i = 0; i < n + m; i++) {
    for (int j = 0; j < n + m; j++) {
      d[i][j] = hypot(X[j] - X[i], Y[j] - Y[i]);
    }
  }
  vector<vector<double>> dp(n + m, vector<double>(1 << (n + m), INF));
  for (int i = 0; i < n + m; i++) {
    dp[i][1 << i] = hypot(X[i], Y[i]);
  }
  for (int i = 0; i < (1 << (n + m)); i++) {
    for (int j = 0; j < n + m; j++) {
      if ((i >> j & 1) == 1) {
        for (int k = 0; k < n + m; k++) {
          if ((i >> k & 1) == 0) {
            double t = d[j][k] / (1 << __builtin_popcount(i >> n));
            int i2 = i | (1 << k);
            dp[k][i2] = min(dp[k][i2], dp[j][i] + t);
          }
        }
      }
    }
  }
  double ans = INF;
  for (int i = 0; i < n + m; i++) {
    for (int j = 0; j < (1 << (n + m)); j++) {
      if ((j & ((1 << n) - 1)) == (1 << n) - 1) {
        ans = min(ans, dp[i][j] + hypot(X[i], Y[i]) /
                                      (1 << __builtin_popcount(j >> n)));
      }
    }
  }
  cout << ans << endl;

  return 0;
}
