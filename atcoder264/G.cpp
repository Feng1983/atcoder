#include<bits/stdc++.h>

using namespace std;

const long long INF  = 1000000000000000000;

int main(){
  int N;
  cin >> N;

  vector<string>T(N);
  vector<int> P(N);
  for(int i  =0;i<N;i++){
    cin >> T[i] >>P[i];
  }
  vector<vector<int>> nxt(27*27, vector<int>(26));
  for(int i=0;i<27;i++){
    for(int j = 0;j<27;j++){
      for(int k = 0; k<26;k++){
        nxt[i*27+j][k] = j*27+k;
      }
    }
  }
  vector<vector<long long>> add(27*27,vector<long long>(26,0));
  for(int i = 0; i<N;i++){
    if(T[i].size()==1){
      for(int j  =0;j <27*27; j++){
        add[j][T[i][0]-'a'] +=P[i];
      }
    }
    if(T[i].size()==2){
      for(int j = 0; j<27;j++){
        add[j*27+(T[i][0]-'a')][T[i][1]-'a']+=P[i];
      }
    }
    if(T[i].size()==3){
      add[(T[i][0]-'a')*27+(T[i][1]-'a')][T[i][2]-'a']+=P[i];
    }
  }

  vector<long long> dp(27*27, -INF);
  dp[26*27+26]=0;
  bool ok=false;
  for(int i = 0; i<=27*27;i++){
    for(int j = 0; j<27*27;j++){
      for(int k =0; k< 26;k++){
        if(dp[nxt[j][k]] <dp[j]+add[j][k]){
          if(i==27*27){
            ok=true;
          }
          dp[nxt[j][k] ]= dp[j]+add[j][k];
        }
      }
    }
  }
  if(ok){
    cout<<"Infinity"<<endl;

  }else{
    long long ans = -INF;
    for(int i = 0; i<27*27-1;i++){
      ans =max(dp[i],ans);
    }
    cout<<ans<<endl;
  }
}

