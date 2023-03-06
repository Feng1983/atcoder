#include "atcoder/modint.hpp"
#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;
int n ;
int r[5005],c[5005];
mint dp[5005][5005];
void solve(){
  cin >> n;
  for(int i=1;i<=n;i++)cin >> r[i];
  for(int i=1;i<=n;i++)cin >> c[i];
  int x0=0, sum=0;
  for(int i=1;i<=n;i++){
    sum+=c[i];
    if(c[i]==2)x0++;
  }
  dp[0][x0]=1;
  for(int i=1;i<=n;i++){
    sum-=r[i];
    for(int x=0;x<=n;x++){
      int  y=sum-2*x;
      if(y<0)break;
      if(r[i]==0)dp[i][x] =dp[i-1][x];
      if(r[i]==1)dp[i][x] =dp[i-1][x+1]*(x+1)+dp[i-1][x]*(y+1);
      if(r[i]==2)dp[i][x] =dp[i-1][x+1]*(x+1)+dp[i-1][x+2]*((x+2)*(x+1)/2)+dp[i-1][x]*((y+2)*(y+1)/2)
        +dp[i-1][x+1]*(x+1)*y;
    }
  }
  if(sum) cout<<0<<endl;
  else cout<<dp[n][0].val()<<endl;

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;

}
