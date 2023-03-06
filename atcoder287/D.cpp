#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string S;
  cin >> S;
  string T;
  cin >> T;
  int n  =S.size(), m  =T.size();
  int c=  0;
  while(c<m){
    if(S[c]==T[c] || S[c]=='?'|| T[c]=='?'){
      c++;
    }else{
      break;
    }
  }
  int d = 0;
  while(d<m){
    if(S[n-1-d] == T[m-1-d] || S[n-1-d] ==
        '?'||T[m-1-d]=='?'){
      d++;
    }else{
      break;
    }
  }
  for(int i =0;i<=m;i++){
    if(i<=c && m-i <=d){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return 0;

}
