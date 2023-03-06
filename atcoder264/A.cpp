#include <bits/stdc++.h>

using namespace std;

void solve(){
  int l, r;
  cin >> l >>r;
  string ans ="atcoder";
  cout<< ans.substr(l-1, r-l+1)<<"\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  

}
