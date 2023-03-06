#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
  }
  int S = 0;
  for (int i = 0; i < n; i++) {
    S += A[i];
  }
  vector<int> cnt(m * 2 + 1, 0);
  for(int i = 0;i<n;i++){
    cnt[B[i]-A[i]+m]++;
  }
  vector<int>dp(m+1,INF);
  dp[S]=0;
  for(int i= -m ;i<=m;i++){

    if(i!=0){
      int c = cnt[m+i];
      vector<int>C;
      int L=1;
      while(L<=c){
        C.push_back(L);
        c-=L;
        L*=2;
      }
      if(c!=0){
        C.push_back(c);
      }
      for(int j: C){
        if(i >0){
          for(int  k =m-i*j;k>=0;k--){
            if(dp[k]!=INF){
              dp[k+i*j] =min(dp[k+i*j],dp[k]+j);
            }
          }
        }else{
          for(int k = -i*j;k<=m;k++){
            if(dp[k]!=INF){
              dp[k+i*j] = min(dp[k+i*j],dp[k]+j);
            }
          }
        }
      }
    }
  }
  for(int i=0;i<=m;i++){
    if(dp[i] ==INF){
      cout<<-1<<endl;
    }else{
      cout<<dp[i]<<endl;
    }
  }

  return 0;
}
