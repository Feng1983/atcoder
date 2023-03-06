#include "atcoder/string.hpp"
#include<bits/stdc++.h>
#include<atcoder/string>
using namespace std;

void solve(){
  int n;
  cin >> n;
  string S;
  cin >> S;
  string T;
  cin >> T;
  string X=S+S+"$"+T+T;
  vector<int>SA =atcoder::suffix_array(X);
  vector<int>LCP =atcoder::lcp_array(X,SA);
  vector<int>P;
  P.push_back(0);
  for(int i =0;i<n*4;i++){
    if(LCP[i]<n){
      P.push_back(i+1);
    }
  }
  P.push_back(n*4+1);
  int cnt=P.size();
  long long ans=0;
  int s=0;
  for(int i = 0;i<cnt-1;i++){
    for(int j=P[i];j<P[i+1];j++){
      if(SA[j] <n){
        s++;
      }
    }
    for(int j =P[i];j<P[i+1];j++){
      if(SA[j] >n*2 && SA[j] <=n*3){
        ans+=s;
      }
    }
  }
  cout<<ans<<endl;

}
int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return  0;
}
