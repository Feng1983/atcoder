#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> f(n+1);
  iota(f.begin(), f.end(), 0);
  for(int i  =2;i*i<=n;i++){
    for(int j= i*i;j<=n;j+=i*i){
      while(f[j]%(i*i)==0){
        f[j]/=i*i;
      }
    }
  }
  long long ans=0;
  vector<int>cnt(n+1);
  for(int i=1;i<=n;i++){
    ans+=2*cnt[f[i]]+1;
    cnt[f[i]]++;
  }
  cout<<ans<<endl;

  return 0;
}
