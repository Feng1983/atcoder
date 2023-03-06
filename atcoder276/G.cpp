#include <bits/stdc++.h>
using namespace std;
const long long mod= 998244353;
vector<int>c ={1,2,3,2,1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int mx = n+m/3;
  vector<long long> inv(mx+1);
  inv[1]=1;
  for(int i=2;i<=mx;i++){
      inv[i] =mod-inv[mod%i]*(mod/i)%mod;
  }
  vector<long long> fact(mx+1);
  vector<long long>finv(mx+1);
  fact[0]=1;
  finv[0]=1;
  for(int i=1;i<=mx;i++){
    fact[i]  =fact[i-1]*i%mod;
    finv[i]  = finv[i-1]*inv[i]%mod;
  }
  vector<long long> f(n*2+3,0);
  for(int i=0;i<=n-1;i++){
    for(int j=0;j<5;j++){
      f[i+j+n-1]+=fact[n-1]*finv[i]%mod*finv[n-1-i]%mod*c[j];
      f[i+j+n-1]%=mod;
    }
  }
  vector<long long> g(m+1,0);
  for(int i= 0;i*3<=m;i++){
    g[i*3] =fact[i+n]*finv[i]%mod*finv[n]%mod;
  }
  long long ans=0;
  for(int i =0;i<=n*2+2;i++){
    if(i<=m){
      ans+=f[i]*g[m-i]%mod;
    }
  }
  ans%=mod;
  cout<<ans<<endl;

  return 0;
}
