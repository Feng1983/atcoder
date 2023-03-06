#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  map<int, array<vector<int>, 2>> p;
  for (int i = 0; i < n; i++) {
    int x = __builtin_ctz(a[i]);
    p[a[i] >> x][0].push_back(x);
    x = __builtin_ctz(b[i]);
    p[b[i] >> x][1].push_back(x);
  }
  ll ans = 0;
  while (!p.empty()) {
    auto [v, f] = *p.rbegin();
    p.erase(p.rbegin()->first);

    if (f[0].size() < f[1].size()) {
      cout << "-1\n";
      return 0;
    }
    sort(f[0].begin(), f[0].end(), std::greater());
    sort(f[1].begin(), f[1].end(), std::greater());
    while (f[0].size() > f[1].size()) {
      int d = f[0].back();
      f[0].pop_back();
      ans += d + 1;
      int t = __builtin_ctz(v >> 1);
      p[v >> (t + 1)][0].push_back(t);
    }
    for (int i = 0; i < int(f[0].size()); i++) {
      ans += abs(f[0][i] - f[1][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
