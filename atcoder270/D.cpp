#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >>k;
  vector<int>A(k);
  for(int i =0;i<k;i++){
    cin >> A[i];
  }
  vector<int>dp(n+1, 0);
  for(int i =1;i<=n;i++){
    for(int j=0;j<k;j++){
      if(i>=A[j]){
        dp[i] =max(dp[i] , A[j]+(i-A[j])-dp[i-A[j]]);
      }
    }
  }
  cout<<dp[n]<<endl;
  return 0;

}
