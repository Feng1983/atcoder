#include<bits/stdc++.h>
using namespace std;
  
using i64=long long;
struct DSU{
  vector<int> f, siz;
  DSU(int n):f(n), siz(n,1){
    iota(f.begin(),f.end(),0);
  }
  int leader(int x){
    while(x!=f[x])x=f[x]=f[f[x]];
    return x;
  }
  bool same(int x, int y){return leader(x)==leader(y);}
  bool merge(int x,int y){
    x =leader(x);
    y= leader(y);
    if(x==y)return false;
    siz[ x] +=siz[y];
    f[y]=x;
    return true;
  }

};
int main(){
  int n ;
  cin >> n;
  vector<vector<int>> adj(n);
  for(int i=0;i<n;i++){
    int u, v;
    cin >> u >> v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> cyc(n);
  vector<int> parent(n,-1), vis(n,-1);
  int cur=0;
  function<void(int)> dfs=[&](int x){
    vis[x]=cur++;
    for(auto y: adj[x]){
      if(y==parent[x]){
        continue;
      }
      if(vis[y] ==-1){
        parent[y]=x;
        dfs(y);
      }else if(vis[x]>vis[y]){
        for(int i=x; i!=y;i=parent[i]){
          cyc[i] =true;
        }
        cyc[y]=true;
      }
    }
  };
  dfs(0);
  DSU dsu(n);
  for(int i  =0;i<n;i++){
    for(auto j: adj[i]){
      if(!cyc[i] ||!cyc[j]){
        dsu.merge(i,j);
      }
    }
  }
  int q;
  cin >> q;
  for(int i =0;i <q;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    cout<<(dsu.same(u,v) ? "Yes":"No")<<endl;
  }

}
