#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 998244353;
int deg[200005];

LL f_pow(LL a, LL b){
  LL res=1, temp=a;
  while(b){
    if(b&1)res= res*temp%mod;
    temp = temp*temp%mod;
    b>>=1;
  }
  return res;
}
LL  fra[200005], inv[200005];
LL C(int a, int b){
  return fra[a]*inv[b]%mod*inv[a-b]%mod;
}

void solve() {
  fra[0] =1;
  for(int i=1;i<=200000;i++)fra[i]=fra[i-1]*i%mod;
  inv[200000]= f_pow(fra[200000],mod-2);
  for(int i=199999;i>=0;i--)inv[i] = inv[i+1]*(i+1)%mod;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i =0;i<m;i++){
    int x, y;
    cin >> x >> y;
    deg[x]++;
    deg[y]++;
  }
  int cnt[2] ={0,0};
  for(int i=1;i<=n;i++)cnt[deg[i]&1]++;
  LL ans = 0;
  for(int i=0;i<=cnt[1]&&  i<=k;i+=2){
    int need =k-i;
    if(need <=cnt[0]){
      ans+=C(cnt[0], need) *C(cnt[1], i)%mod;
      ans%=mod;
    }
  }
  cout<<ans<<endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
