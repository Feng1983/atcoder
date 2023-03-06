#include <bits/stdc++.h>

using namespace std;

void solve(){
  string s;
  cin >> s;
  string t="atcoder";
  vector<int>p(7);
  for(int i=0;i<7;i++){
    for(int j=0;j<7;j++){
      if(s[i] == t[j]){
        p[i]=j;
      }
    }
  }

  int ans=0;
  for(int i = 0;i<7;i++){
    for(int j =i+1;j<7;j++){
      if(p[i] >p[j]){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  

}
