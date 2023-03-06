#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x;
  cin >> n >> x;
  vector<int>a(n),b(n);

  for(int i=0;i<n;i++){
    cin >>a[i]>>b[i];
  }
  long long ans =(long long)4e18;
  long long sum =0;
  for(int i = 0 ;i<n&& i<x;i++){
    sum+=a[i]+b[i];
    long long cur= sum+(long long)b[i]*(x-i-1);
    ans =min(ans, cur);
  }
  cout<<ans<<endl;
  return 0;
}
