#include<bits/stdc++.h>

using namespace std;

const long long INF= 1000000000000000;

int main(){
  cout<< fixed << setprecision(20);
  int n;
  cin >> n;
  vector<double> dp(n, 0);
  dp[n-1] = 3.5;

  for(int i  =n-2; i>=0;i--){
    for(int j  =1;j<=6;j++){
      dp[i] +=max((double)j, dp[i+1])/6;
    }
  }
  cout<<dp[0]<<endl;
  return 0;
}
