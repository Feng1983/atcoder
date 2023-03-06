#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  int c = -1;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      if (A[i] != A[i - 1]) {
        c = -1;
      }
    }
    c++;
    for (int j = 0; j <= i; j++) {
      if (i + 1 - c - j >= 0) {
        dp[i + 1][j] += dp[i][j] * (c + j) % mod;
        dp[i + 1][j] %= mod;
        dp[i + 1][j + 1] = dp[i][j] * (i + 1 - c - j) % mod;
        dp[i + 1][j + 1] %= mod;
      }
    }
  }
  cout << dp[n][k + 1] << endl;
  return 0;
}
