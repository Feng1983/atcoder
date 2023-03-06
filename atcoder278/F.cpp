#include<bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<pair<unsigned char, unsigned char>> info(n);
  for(auto & [first,last]:info){
    string S;
    cin >> S;
    first=S.front()-'a';
    last=S.back()-'a';
  }
  vector<unsigned>dp(1UL <<n);
  for(unsigned S{1};S< 1UL<<n;++S){
    for(unsigned c{};c<n;++c){
      if(1 & S >> c){
        dp[S]|=(1UL& ~dp[S^1UL<<c] >> info[c].second)<<info[c].first;
      }
    }
  }
  cout<<(dp.back() ? "First":"Second")<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
