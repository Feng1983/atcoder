#include <bits/stdc++.h>
using namespace std;

const long long MOD=998244353;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  //dp n, m , k
  //
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long >>dp(n, vector<long long> (m,0));
  for(int i=0;i<m;i++){
    dp[0][i] =1;
  }
  for(int i = 0; i< n-1;i++){
    vector<long long > S(m+1);
    S[0] = 0;
    for(int j=0;j<m;j++){
      S[j+1] = S[j] +dp[i][j];
      S[j+1] %= MOD;
    }
    for(int j=0;j<m ;j++){
      dp[i+1][j] = S[m];
      if(k>0){
        dp[i+1][j] -= S[min(j+k,m)]-S[max(j-k+1, 0)];

      }
      dp[i+1][j]+=MOD;
      dp[i+1][j]%=MOD;
    }
  }
  long long ans=0;
  for(int i = 0;i<m;i++){
    ans+=dp[n-1][i];
  }
  ans%=MOD;
  cout<< ans<< endl;

  return 0;
}
