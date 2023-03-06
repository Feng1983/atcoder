#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int i = 0;i < m;i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int q;
  cin >> q;
  for(int i = 0; i< q; i++){
    int x, k;
    cin >> x>> k;
    x--;
    set<int> s;
    function<void(int,int)> dfs= [&](int x, int d){
      s.insert(x);
      if(d > 0){
        for(auto y: adj[x]){
          dfs(y, d-1);
        }
      }
    };
    dfs(x,k);
    int ans=0;
    for(auto x: s){
      ans+=(x+1);
    }
    cout<<ans<<endl;
  }

  return 0;
}
