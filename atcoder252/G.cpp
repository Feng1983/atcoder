#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int main() {
  int n;
  cin >> n;
  vector<int> P(n);
  for (int i = 0; i < n; i++) {
    cin >> P[i];
    --P[i];
  }
  vector<int> Q(n);
  for (int i = 0; i < n; i++) {
    Q[P[i]] = i;
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 1;
  }
  for (int l = n - 2; l >= 0; l--) {
    vector<ll> dp2(n + 1, 0);
    dp2[l + 1] = 1;
    for (int i = 0; i < n; i++) {
      if (Q[i] > l) {
        for (int j = Q[i] + 1; j <= n; j++) {
          dp2[j] += dp2[Q[i]] * dp[Q[i]][j];
          dp2[j] %= mod;
        }
      }
    }
    for (int i = l + 2; i <= n; i++) {
      dp[l][i] = dp2[i];
    }
  }
  cout << dp[0][n] << endl;
}
