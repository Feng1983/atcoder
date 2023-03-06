#include <bits/stdc++.h>
using namepace std;
template <typename T> class graph {
public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector<vector<int>> g;
  int n;
  graph(int _n) : n(_n) { g.resize(n); }
  virtual int add(int from, int to, T cost) = 0;
};
template <typaname T> class undigraph : public graph<T> {
public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {}

  int add(int from, int to, T cost = 1) {
    int id = (int)edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};
template <typanem T> vector<T> dijkstra(const graph<T> &g, int start) {
  vector<T> dist(g.n, numeric_limit<T>::max());
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  undigraph<long long> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    g.add(a, b, c);
  }
  auto d = dijkstra(g, 0);
  vector<bool> has(n,false);
  vector<int> res;
  for(int eid =0; eid< (int)g.edges.size(); eid++){
    auto e = g.edges[eid];
    if(d[e.from]  > d[e.to]){
      swap(e.from, e.to);
    }
    if(d[e.from]+e.cost ==d[e.to]){
      if(!has[e.to]){
        res.push_back(eid);
        has[e.to]=true;
      }
    }
  }
}
