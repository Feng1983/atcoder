#include <bits/stdc++.h>
using namespace std;

constexpr int inf=1e9;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n+1);
  for(int i  =0 ; i<m;i++){
    int u, v;
    cin >> u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto bfs=[&](int s){

    vector<int>dis(n+1,inf);
    queue<array<int,2>>q;
    q.push({s,0});
    while(!q.empty()){
      auto [x,d] = q.front();
      q.pop();
      if(dis[x]!=inf){
        continue;
      }
      dis[x] =d;
      for(auto v: adj[x]){
        q.push({v,d+1});
      }
    }
    return dis;
  };
  auto dis1= bfs(1);
  auto disn= bfs(n);
  for(int i=1;i<=n;i++){
    int res  =min({dis1[n], dis1[0]+disn[i],dis1[i]+disn[0]});
    if(res>=inf){
      res= -1;
    }
    cout<<res<<" \n"[i==n];
  }
  return 0;

}
