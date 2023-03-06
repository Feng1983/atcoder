#include <bits/stdc++.h>

using namespace std;
void dfs(vector<int>& a, int n, int m , int p){
  if(a.size()==n){
    for(int i=0;i<n;i++){
      cout<< a[i];
      if(i<n-1){
        cout<<' ';
      }
    }
    cout<<endl;
  }
  else{
    for(int i =p;i<=m;i++){
      a.push_back(i);
      dfs(a, n, m, i+1);
      a.pop_back();
    }
  }
}

void solve() {
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  //solve();
  int n, m;
  cin >> n >> m;
  vector<int>a;
  dfs(a, n, m,1);

  return 0;
}
