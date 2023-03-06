#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; 
  cin >> n;
  string s;
  cin >> s;
  map<int,int> mf;

  int res = 0;
  for(int i = 0 ;i<n;i++){
    int w;
    cin >> w;
    res += (s[i]=='1');
    mf[w] += (s[i]=='0'?1:-1);
  }
  int ans = res;
  for(auto [_,x]:mf){
    res+=x;
    ans = max(ans, res);
  }
  cout<<ans<<endl;

  return 0;

}
