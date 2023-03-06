#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>>adj(n);

  vector<int>deg(n);
  for(int i=0;i< m;i++){
    int x, y;
    cin >>  x >> y;
    x--,y--;
    adj[x].push_back(y);
    deg[y]+=1;
  }
  vector<int>a(n);
  queue<int>q;
  for(int i=0;i<n;i++){
    if(deg[i]==0){
      q.push(i);
    }
  }
  for(int v=1;v<=n;v++){
    if(q.size()!=1){
      cout<<"No\n";
      return 0;
    }
    int x =q.front();
    q.pop();
    a[x]=v;
    for(auto y: adj[x]){
      deg[y]-=1;
      if(deg[y]==0){
        q.push(y);
      }
    }
  }
  cout<<"Yes\n";
  for(int i=0;i<n;i++){
    cout<<a[i] <<" \n"[i==n-1];
  }
  return 0;
}
