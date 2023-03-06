#include<bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int>siz(n);
  auto dfs=[&](auto self, int x, int p)->void{
    siz[x] =1;
    for(auto y:adj[x]){
      if(y==p){
        continue;
      }
      self(self, y,x);
      siz[x]+=siz[y];
    }
  };
  dfs(dfs, 0,-1);
  auto find =[&](auto self, int x, int p)->int{

    for(auto y:adj[x]){
      if(y!=p && 2*siz[y] >n){
        return self(self,y,x);
      }
    }
    return x;
  };
  int x =find(find,0,-1);
  vector<int>p(n),dep(n);
  int len =0;

  vector<vector<int>> s;
  for(auto y: adj[x]){
    vector<int>a;
    auto dfs1=[&](auto self, int x, int p)->void{
      a.push_back(x);
      for(auto y: adj[x]){
        if(y==p){
          continue;
        }
        dep[y]=dep[x]+1;
        self(self,y,x);
      }
    };
    dep[y] =1;
    dfs1(dfs1,y,x);
    sort(a.begin(),a.end(), [&](int x,int y){
        return dep[x] <dep[y];
        });
    s.push_back(a);
  }
  iota(p.begin(),p.end(),0);
  priority_queue<pair<int,int>>h;
  for(int i=0;i<s.size();i++){
    h.emplace(s[i].size(), i);
  }
  while(h.size() >1){
    auto [_1,i]= h.top();
    h.pop();
    auto [_2,j]=h.top();
    h.pop();
    swap(p[s[i].back()],p[s[j].back()]);
    s[i].pop_back();
    s[j].pop_back();
    if(!s[i].empty()){
      h.emplace(s[i].size(),i);
    }
    if(!s[j].empty()){
      h.emplace(s[j].size(),j);
    }
  }
  if(!h.empty()){
    auto[_,i]= h.top();
    swap(p[x],p[s[i].back()]);
  }
  for(int i=0;i<n;i++){
    cout<<p[i]+1<<" \n"[i==n-1];
  }

  return 0;
}
