#include <bits/stdc++.h>

using namespace std;

void solve(){
  int c, r;
  cin >> c >> r;

  c--;r--;
  r= min(r, 14-r);
  c= min(c, 14-c);
  if(min(r,c)%2==0){
    cout<<"black"<<endl;
  }else{
    cout<<"white"<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  

}
