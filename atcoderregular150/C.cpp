#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,m,k;
  cin >>  n >> m >> k;
  vector<vector<int>>g(n);
  for(int i=0;i<m;i++){
    int x, y;
    cin >> x >> y;
    --x,--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  vector<int>b(k);
  for(int i=0;i<k;i++){
    cin >> b[i];
  }
  const int inf=(int)1e9;
  vector<int>d(n,inf);
  d[0] = (a[0]==b[0] ?1:0);
  set<pair<int,int>>s;
  s.emplace(d[0],0);
  while(!s.empty()){
    int i  =s.begin()->second;
    s.erase(s.begin());
    for(int j :g[i]){
      int ft= d[i];
      if(ft<k&& a[j]==b[ft]){
        ft+=1;
      }
      if(ft<d[j]){
        s.erase(make_pair(d[j],j));
        d[j] =ft;
        s.emplace(d[j],j);
      }
    }
  }
  cout<<(d[n-1]>=k?"Yes":"No")<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  //cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
