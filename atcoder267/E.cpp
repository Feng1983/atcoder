#include<bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> A(n);

  for(int i =0;i<n;i++){
    cin >> A[i];
  }

  vector<vector<int>> E(n);
  for(int i = 0;i <m;i++){
    int u,v;
    cin >> u >>v;
    u--,v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<long long> S(n,0);
  for(int i = 0;i<n;i++){
    for(int j: E[i]){
      S[i]+=A[j];
    }
  }
  vector<bool> used(n,false);
  priority_queue<pair<long long, int>,vector<pair<long long ,int>>, greater<pair<long long,int>>>pq;
  for(int i=0;i<n;i++){
    pq.push(make_pair(S[i],i));
  }
  long long ans = 0;
  while(!pq.empty()){
    long long c = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if(!used[v]){
      used[v]=true;
      ans=max(ans, c);
      for(int w: E[v]){
        S[w]-=A[v];
        if(!used[w]){
          pq.push(make_pair(S[w],w));
        }
      }
    }
  }
  cout<<ans<<endl;

  return 0;

}
