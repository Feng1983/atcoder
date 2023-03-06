#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n ;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  map<int,int> m;
  for(int i = 0;i<n;i++){
    m[a[i]]++;
  }
  long long ans= (long long)n*n*n;
  for(auto &p: m){
    long long x = p.second;
    ans -=  x*x*x;
    ans-= 3*x*x*(n-x);
  }
  cout<<ans/6<<endl;
  return 0;
}
