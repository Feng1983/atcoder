#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> a(n);
  vector<mint>y(n);

  mint s,x,z;
  for(int  i=0;i<n;i++)cin >> a[i];
  y[n-1]=0;
  s=0;
  for(int i=n-1;i>=1;i--){
    x=((mint)n/i).pow(a[i]-a[i-1]);
    z =(n-s)/(n-i);
    y[i-1]=(y[i]+z)*x-z;
    s+=y[i-1];
  }
  cout<<y[0].val()<<endl;
  return 0;
}
