#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i = 0;i<n;i++){
    cin >> x[i];
    --x[i];
  }
  vector<int> c(n);
  for(int i=0;i<n;i++){
    cin >> c[i];
  }
  vector<bool> was(n,false);
  vector<int>deg(n);
  for(int i = 0; i<n;i++){
    ++deg[x[i]];
  }
  vector<int> que;
  for(int i=0;i<n;i++){
    if(deg[i] ==0){
      que.push_back(i);
      was[i]=true;
    }
  }
  for(int b=0;b<(int)que.size();b++){
    int to = x[que[b]];
    if(--deg[to]==0){
      que.push_back(to);
      was[to]=true;
    }
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    if(was[i]){
      continue;
    }
    int p=i;
    int cur= c[p];
    while(!was[p]){
      cur =min(cur, c[p]);
      was[p]=true;
      p=x[p];
    }
    ans+=cur;
  }
  cout<<ans<<endl;

  return 0;

}
