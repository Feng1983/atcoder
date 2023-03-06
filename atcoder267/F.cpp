#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> d1(n, -1);
  d1[0] = 0;
  queue<int> Q1;
  Q1.push(0);
  int s;
  while (!Q1.empty()) {
    int v = Q1.front();
    Q1.pop();
    s = v;
    for (int w : E[v]) {
      if (d1[w] == -1) {
        d1[w] = d1[v] + 1;
        Q1.push(w);
      }
    }
  }
  vector<int> p2(n, -1);
  vector<int> d2(n, -1);
  d2[s] = 0;
  queue<int> Q2;
  Q2.push(s);
  int t;
  while (!Q2.empty()) {
    int v = Q2.front();
    Q2.pop();
    t = v;
    for (int w : E[v]) {
      if (d2[w] == -1) {
        p2[w] = v;
        d2[w] = d2[v] + 1;
        Q2.push(w);
      }
    }
  }
  vector<int> p3(n, -1);
  vector<int> d3(n, -1);
  d3[t] = 0;
  queue<int> Q3;
  Q3.push(t);
  while (!Q3.empty()) {
    int v = Q3.front();
    Q3.pop();
    for (int w : E[v]) {
      if (d3[w] == -1) {
        p3[w] = v;
        d3[w] = d3[v] + 1;
        Q3.push(w);
      }
    }
  }
  vector<vector<int>> pp1(18, vector<int>(n, -1));
  vector<vector<int>> pp2(18, vector<int>(n, -1));
  pp1[0] = p2;
  pp2[0] = p3;

  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < n; j++) {
      if (pp1[i][j] != -1) {
        pp1[i + 1][j] = pp1[i][pp1[i][j]];
      }
      if (pp2[i][j] != -1) {
        pp2[i + 1][j] = pp2[i][pp2[i][j]];
      }
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, k;
    cin >> u >> k;
    u--;
    if (d2[u] >= k) {
      for (int j = 0; j < 18; j++) {
        if ((k >> j & 1) == 1) {
          u = pp1[j][u];
        }
      }
      cout << u + 1 << endl;
    } else if (d3[u] >= k) {
      for (int j = 0; j < 18; j++) {
        if ((k >> j & 1) == 1) {
          u = pp2[j][u];
        }
      }
      cout << u + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
