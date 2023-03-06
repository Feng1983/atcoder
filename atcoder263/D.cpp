#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, L, R;
  cin >> N >> L >> R;
  vector<int> a(N);
  for(int i  =0;i<N;i++){
    cin >> a[i];
  }
  vector<vector<long long>> dp(3, vector<long long>(N+1,INF));
  dp[0][0] = 0; dp[1][0]=0;dp[2][0]=0;
  for(int i =0;i<N;i++){
    dp[0][i+1] = dp[0][i]+L;
    dp[1][i+1] = dp[1][i]+a[i];
    dp[2][i+1] = dp[2][i]+R;
    dp[1][i+1]  =min(dp[1][i+1], dp[0][i+1]);
    dp[2][i+1] = min(dp[2][i+1],dp[1][i+1]);
  }
  cout<<dp[2][N]<<endl;


  return 0;
}
