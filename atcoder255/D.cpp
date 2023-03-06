#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n ,q;
  cin >> n >> q;
  vector<int> a(n);
  for(int i = 0; i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long > s(n+1);
  for(int i=1;i<=n;i++){
    s[i]=s[i-1]+a[i-1];
  }
  for(int i  = 0; i< q;i++){
    int x;
    cin >> x;
    int idx=  lower_bound(a.begin(),a.end(), x)-a.begin();
    long long  ans = 0;
    ans+=(long long )x*idx -s[idx];
    ans +=(s[n]-s[idx])-(long long)x*(n-idx);
    cout<<ans<<endl;
  }

  return 0;

}
