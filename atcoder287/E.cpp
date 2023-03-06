#include<bits/stdc++.h>
using namespace std;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<string>s(N);

  for(int i=0;i<N;i++){
    cin >> s[i];
  }
  vector<pair<string,int>> P(N);
  for(int i=0;i<N;i++){
    P[i]  =make_pair(s[i],i);
  }
  sort(P.begin(),P.end());
  vector<int>L(N-1,0);
  for(int i  =0;i<N-1;i++){
    while(L[i] <P[i].first.size() && L[i]<P[i+1].first.size()){
      if(P[i].first[L[i]] == P[i+1].first[L[i]]){
        L[i]++;
      }else{
        break;
      }
    }
  }
  vector<int> ans(N,0);
  for(int i =0;i<N-1;i++){
    ans[P[i].second] = max(ans[P[i].second],L[i]);
    ans[P[i+1].second] = max(ans[P[i+1].second], L[i]);
  }
  for(int i =0;i<N;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
