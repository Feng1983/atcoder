#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

void solve(){
  int N, D;
  cin >> N >> D;
  vector<int> p(N);
  for(int i  =0; i<N;i ++){
    cin >> p[i];
  }
  vector<int>q(N);
  for(int i = 0;i <N;i++){
    cin >> q[i];
  }
  vector<int> s(N);
  for(int  i =0;i < N;i++){
    s[i]  =abs(p[i] -q[i]);
  }
  vector<vector<long long>>dp(D+1, vector<long long>(D+1,0));
  dp[0][0] =1;
  for(int i =0;i<N;i++){
   vector<vector<long long>>dp2(D+1, vector<long long>(D+1,0));  
   vector<vector<long long>>dp3(D+1, vector<long long>(D+1,0)); 
   for(int j =0;j<=D;j++){
     for(int k=0;k<=D;k++){
       if(j + k + s[i] <=D * 2 && dp[j][k]>0){
         int x1=j, y1= k +s[i];
         if(y1 >= D){
           x1+=y1-D;
           y1=D;
         }
         dp2[x1][y1]+=dp[j][k];
         int x2= j+s[i]+1, y2=k-1;
         if(x2<=D && y2>=0){
           dp2[x2][y2]+=MOD-dp[j][k];
         }
         int x3=j+s[i]+1, y3=k+1;
         if(x3<=D && y3<=D){
           dp3[x3][y3] +=dp[j][k];
         }
         int x4= j+1, y4=k+s[i]+1;
         if(x4<=D && y4<=D){
           dp3[x4][y4]+=dp[j][k];
         }
       }
     }
   }
   for(int j =0;j<D;j++){
     for(int k =0;k<=D;k++){
       if( k>0){
         dp2[j+1][k-1]+=dp2[j][k];
         dp2[j+1][k-1]%=MOD;
       }
       if(k <D){
         dp3[j+1][k+1]+=dp3[j][k];
         dp3[j+1][k+1]%=MOD;
       }
     }
   }
   for(int j = 0;j<=D;j++){
     for(int k=0;k<=D;k++){
       dp[j][k] =(dp2[j][k]+dp3[j][k])%MOD;
     }
   }
  }
  long long ans =0;
  for(int i =0;i<=D;i++){
    for(int j =0;j<=D;j++){
      ans+=dp[i][j];
    }
  }
  ans%=MOD;
  cout<<ans<<endl;
}

int main(){
  solve();

  return 0;

}
