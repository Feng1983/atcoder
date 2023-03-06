#include<bits/stdc++.h>

using namespace std;
#define mod 998244353

int main(){
  int n;
  cin >> n;
  vector<int> p(n+1);
  for(int i =2;i<=n;i++){
    cin >> p[i];
  }
  vector<int> d(n+1,0);
  vector<vector<long long>> dp(n+1, vector<long long>(20,0));
  vector<vector<long long>> csum(n+1, vector<long long>(20,0));

  p[1]=0;
  dp[1][0]=1;
  csum[0][0] = 1;
  cout<<"1\n";

  for(int i =2;i<=n;i++){
    d[i] = d[p[i]]+1;
    if(d[i] <20){
      long long val = 1;
      int v, curd;
      v=i,curd=0;
      while(1){
        int par=p[v];
        long long nval = val*(mod+csum[par][curd]-dp[v][curd])%mod;
        csum[par][curd] +=val;
        csum[par][curd]%=mod;
        dp[v][curd]+=val; dp[v][curd]%=mod;
        if(par==0){
          break;
        }
        v=par;
        curd++;
        val =nval;
      }
    }
    long long res = 0;
    for(int i =0; i<20;i++){
      res+= csum[0][i];res%=mod;
    }
    cout<<res<<"\n";
  }

  return 0;
}



