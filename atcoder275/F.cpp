#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MOD = 998244353;
const int INF =100000000;
void solve() {
  int n,m;
  cin >> n >> m;
  vector<int>a(n);
  for(int i  =0;i<n;i++){
    cin >>a[i];
  }

  vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(m+1,INF)));
  dp[0][0][0] =0;
  dp[1][0][0]=1;
  for(int i =0;i<n;i++){
    for(int j=0;j<=m;j++){
      for(int k=0;k<2;k++){
        dp[1][i+1][j] =min(dp[1][i+1][j],dp[0][i][j]+1);
        dp[1][i+1][j] =min(dp[1][i+1][j],dp[1][i][j]);
      }
      if(j+a[i]<=m){
        dp[0][i+1][j+a[i]] =min(dp[0][i+1][j+a[i]],dp[0][i][j]);
        dp[0][i+1][j+a[i]]=min(dp[0][i+1][j+a[i]],dp[1][i][j]);
      }
    }
  }
  for(int i=1;i<=m;i++){
    int ans =min(dp[0][n][i],dp[1][n][i]);
    if(ans==INF){
      cout<<-1<<endl;
    }else{
      cout<<ans<<endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
