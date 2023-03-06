#include<bits/stdc++.h>
using namespace std;

const int INF=10000000;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A[i][j];
    }
  }
  vector<vector<vector<int>>>dp(H+1,vector<vector<int>>(2,vector<int>(2,INF)));
  dp[0][0][0]=0;
  dp[0][0][1]=1;
  for(int i=0;i<H;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        for(int l=0;l<2;l++){
          bool ok=true;
          for(int y=0;y<W;y++){
            bool ok2=false;
            if(i>0){
              if((A[i][y]^k)==(A[i-1][y]^j)){
                ok2=true;
              }
            }
            if(i<H-1){
              if((A[i][y]^k)==(A[i+1][y]^l)){
                ok2=true;
              }
            }
            if(y>0){
              if((A[i][y]^k)==(A[i][y-1]^k)){
                ok2=true;
              }
            }
            if(y<W-1){
              if((A[i][y]^k)==(A[i][y+1]^k)){
                ok2=true;
              }
            }
            if(!ok2){
              ok=false;
            }
          }
          if(ok){
            dp[i+1][k][l]=min(dp[i+1][k][l],dp[i][j][k]+l);
          }
        }
      }
    }
  }
  int ans =INF;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      ans =min(ans, dp[H][i][j]);
    }
  }
  if(ans==INF){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
}
