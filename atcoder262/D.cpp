#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod=998244353;
int a[102][102];
void solve(){

  int n;
  cin >> n;
  vector<int>p(n+1);
  for(int i =0;i<n;i++){

    cin >> p[i+1];
  }
  ll ans =0;
  for(int i =1;i<=n;i++){
    int dp[102][102];
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    for(int j=1;j<=n;j++){
      for(int t=i-1;t>=0;t--){
        for(int b=0;b<i;b++){
          dp[t+1][(b+p[j])%i]+=dp[t][b];
          dp[t+1][(b+p[j])%i]%=mod;
        }
      }
    }
    ans+=dp[i][0];
  }

  cout<<(ans%mod)<<endl;
} 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}

