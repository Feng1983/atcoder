#include<bits/stdc++.h>
using namespace std;


 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n,0));
  for(int i= 0;i<m;i++){
    int x,y;
    cin  >> x >> y;
    --x;--y;
    g[x][y]=g[y][x]=1;
  }
  int ans = 0;
  for(int i =0;i<n;i++){
    for(int j = i+1;j<n;j++){
      for(int k= j+1;k<n;k++){
        ans+= (g[i][j]&g[j][k]&g[k][i]);
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}

