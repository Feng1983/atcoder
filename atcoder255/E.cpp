#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> s(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> s[i];
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  vector<int> a(n);
  vector<long long> b(n);
  a[0] = 1;
  b[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    b[i + 1] = s[i] - b[i];
    a[i + 1] = -a[i];
  }
  map<long long, int> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      mp[(x[j] - b[i]) / a[i]]++;
    }
  }
  int ans = 0;
  for (auto x : mp) {
    ans = max(ans, x.second);
  }
  cout << ans << endl;

  return 0;
}
