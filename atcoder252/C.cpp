#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i= 0;i<n;i++){
    cin >> a[i];
  }
  int ans=1e9;
  for(char c='0';c <='9';c++){
    map<int,int> m;
    int cur= 0 ;
    for(int i=0;i<n;i++){
      int j  =a[i].find(c);
      if(m.find(j)==m.end()){
        m[j] = j;
      }else{
        m[j]+=10;
      }
      cur = max(cur, m[j]);
    }
    ans = min(ans, cur);
  }
  cout<< ans<<endl;

  return 0;
}
