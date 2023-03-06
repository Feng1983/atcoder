#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int>p(n);
  for(int i=1;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int>d(n);
  d[0]=0;
  for(int i =1;i<n;i++){
    d[i] = d[p[i]]+1;
  }
  vector<long long>fact(n);
  fact[0]=1;
  for(int i  =1;i<n;i++){
    fact[i]  =fact[i-1]*i%MOD;
  }
  vector<long long>S(n);
  S[0]=1;
  for(int i=0;i<n-1;i++){
    S[i+1] = (S[i]*(i+2)+fact[i+1])%MOD;
  }


  vector<long long> inv(n+1);
  inv[1] =1;
  for(int i=2;i<=n;i++){
    inv[i]  =MOD-inv[MOD%i]*(MOD/i)%MOD;
  }
  vector<long long>finv(n+1);
  finv[0]=1;
  for(int i=1;i<=n;i++){
    finv[i]  =finv[i-1]*inv[i]%MOD;
  }
  for(int i=0;i<n;i++){
    S[i] *=finv[i+1];
    S[i] %=MOD;
  }
  long long ans=0;
  for(int i = 0;i<n;i++){
    ans+=S[d[i]];
  }
  ans%=MOD;
  cout<<ans<<endl;

  return 0;
}
