#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> E(N);

  for(int i=0;i<N-1;i++){
    int  a, b ;
    cin >> a >> b;
    a--;b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> p(N,-1);
  vector<vector<int>> c(N);
  vector<int> bfs;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int v =Q.front();
    Q.pop();
    bfs.push_back(v);
    for(int w: E[v]){
      if(w!= p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(),bfs.end());
  vector<vector<vector<long long>>> dp(2,vector<vector<long long>>(N));
  for(int v: bfs){
    int cnt=c[v].size();
    vector<vector<vector<long long>>> dp2(2,vector<vector<long long>>(cnt+1));
    dp2[0][0]={1};
    dp2[1][0]={1};
    for(int i=0;i<cnt;i++){
      int w =c[v][i];
      int sz1=dp2[0][i].size();
      int sz2=dp[0][w].size();
      dp2[0][i+1].resize(sz1+sz2,0);
      dp2[1][i+1].resize(sz1+sz2,0);
      for(int j =0;j<sz1;j++){
        for(int k=0;k<sz2;k++){
          dp2[0][i+1][j+k]+=dp2[0][i][j]*dp[0][w][k];
          dp2[0][i+1][j+k]%=MOD;
          dp2[0][i+1][j+k+1]+=dp2[0][i][j]*dp[1][w][k];
          dp2[0][i+1][j+k+1]%=MOD;
          dp2[1][i+1][j+k]  +=dp2[1][i][j]*(dp[0][w][k]+dp[1][w][k]);
          dp2[1][i+1][j+k] %=MOD;
        }
      }
    }
    dp[0][v] =dp2[0][cnt];
    dp[1][v]= dp2[1][cnt];
  }
  vector<long long> ans(N+1, 0);
    for(int i =0;i<N;i++){
      ans[i] +=dp[0][0][i];
      ans[i]%=MOD;
      ans[i+1]+=dp[1][0][i];
      ans[i+1]%=MOD;
    }

  for(int i=1;i<=N;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
