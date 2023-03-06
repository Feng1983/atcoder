#include <bits/stdc++.h>
#include <tuple>
#include <utility>
using namespace std;
const int INF = 1000000000;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++) {
    int u, v, a;
    cin >> u >> v >> a;
    u--;
    v--;
    E[u].push_back(make_pair(a, v));
    E[v].push_back(make_pair(a, u));
  }
  vector<int> s(k);
  for (int i = 0; i < k; i++) {
    cin >> s[i];
    s[i]--;
  }
  vector<bool> S(n, false);
  for (int i = 0; i < k; i++) {
    S[s[i]] = true;
  }

  vector<vector<int>> d(2, vector<int>(n, INF));
  deque<tuple<int, int, int>> dq;
  dq.push_back(make_tuple(0, 0, 0));
  while (!dq.empty()) {
    int c = get<0>(dq.front());
    int t = get<1>(dq.front());
    int v = get<2>(dq.front());
    dq.pop_front();
    if (d[t][v] == INF) {
      d[t][v] = c;
      if (S[v]) {
        // has switch;
        if (d[t ^ 1][v] == INF) {
          dq.push_front(make_tuple(c, t ^ 1, v));
        }
      }
      for (auto P : E[v]) {
        if (P.first != t) {
          int w = P.second;
          if (d[t][w] == INF) {
            dq.push_back(make_tuple(c + 1, t, w));
          }
        }
      }
    }
  };
  int ans = min(d[0][n - 1], d[1][n - 1]);
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
