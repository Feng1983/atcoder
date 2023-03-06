#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj0(n), adj1(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      if (s[j - 1] == '1') {
        adj0[i].push_back(i + j);
        adj1[i + j].push_back(i);
      }
    }
  }

  auto bfs = [&](auto &adj, int s) {
    queue<int> q;
    q.push(s);
    vector<int> dis(n, -1);
    dis[s] = 0;

    while (!q.empty()) {
      int x = q.front();
      q.pop();

      for (auto y : adj[x]) {
        if (dis[y] == -1) {
          dis[y] = dis[x] + 1;
          q.push(y);
        }
      }
    }
    return dis;
  };
  auto d0 = bfs(adj0, 0);
  auto d1 = bfs(adj1, n - 1);

  vector<int> ans(n, -1);
  for (int x = 0; x < n; x++) {
    for (auto y : adj0[x]) {
      if (d0[x] != -1 && d1[y] != -1) {
        int res = d0[x] + d1[y] + 1;
        for (int z = x + 1; z < y; z++) {
          if (ans[z] > res || ans[z] == -1) {
            ans[z] = res;
          }
        }
      }
    }
  }
  for (int i = 1; i < n - 1; i++) {
    cout << ans[i] << " \n"[i == n - 2];
  }
  return 0;
}
