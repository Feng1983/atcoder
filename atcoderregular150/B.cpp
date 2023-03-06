#include<bits/stdc++.h>
using namespace std;

void solve(){
  int a, b;
  cin >> a>> b;
  int ans =(int)2e9;
  int x =0;
  while(x<ans){
    int r =(b+(a+x)-1)/(a+x);
    int y = r*(a+x)-b;
    ans =min(ans, x+y);
    if(r==1){
      break;
    }
    x=(b+(r-2))/(r-1)-a;
  }
  cout<<ans<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
