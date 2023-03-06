#include<bits/stdc++.h>
using namespace std;

const long long INF=1000000000000000;
void solve(){

  int n,x;
  cin >> n >> x;
  vector<int>Y(n);
  for(int i  =0;i<n;i++){
    cin >>Y[i];
  }
  vector<int>Z(n);
  for(int i = 0;i<n;i++){
    cin >>Z[i];
  }
  vector<int>C;
  C.push_back(0);
  C.push_back(x);
  for(int i = 0 ;i<n;i++){
    C.push_back(Y[i]);
    C.push_back(Z[i]);
  }
  sort(C.begin(),C.end());
  C.erase(unique(C.begin(),C.end()), C.end());
  int cnt=C.size();
  int S= lower_bound(C.begin(), C.end(),0)-C.begin();
  x =lower_bound(C.begin(),C.end(),x)-C.begin();
  for(int i  =0;i<n;i++){
    Y[i]  =lower_bound(C.begin(), C.end(),Y[i])-C.begin();
    Z[i]  =lower_bound(C.begin(), C.end(),Z[i])-C.begin();
  }
  vector<int>W(cnt,-1);
  for(int i  =0;i<n;i++){
    W[Y[i]]=i;
  }
  vector<vector<vector<long long>>> dp(2,vector<vector<long long>>(cnt+1,vector<long long>(cnt+1,INF)));
  dp[0][S][S+1]=0;
  dp[1][S][S+1]=0;
  for(int i  =S;i>=0;i--){
    for(int j  =S+1;j<=cnt;j++){
      if(i>0){
        bool ok= true;
        if(W[i-1]!=-1){
          if(!(i<=Z[W[i-1]]&& Z[W[i-1]]<j)){
            ok=false;
          }
        }
        if(ok){
          dp[0][i-1][j]=min(dp[0][i-1][j],dp[0][i][j]+(C[i]-C[i-1]));
          dp[0][i-1][j]=min(dp[0][i-1][j],dp[1][i][j]+(C[j-1]-C[i-1]));
        }
      }
      if(j<cnt){
        bool ok=true;
        if(W[j] !=-1){
          if(!(i<=Z[W[j]] && Z[W[j]]<j)){
            ok=false;
          }
        }
        if(ok){
          dp[1][i][j+1] =min(dp[1][i][j+1],dp[0][i][j]+(C[j]-C[i]));
          dp[1][i][j+1] =min(dp[1][i][j+1],dp[1][i][j]+(C[j]-C[j-1]));
        }
      }
    }
  }
  long long ans= INF;
  for(int i=0;i<=S;i++){
    for(int j=S+1;j<=cnt;j++){
      if(i<=x&& x<j){
        ans =min(ans, dp[0][i][j]);
        ans =min(ans, dp[1][i][j]);
      }
    }
  }
  if(ans==INF){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
