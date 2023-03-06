#include<bits/stdc++.h>
using namespace std;
const long long MOD= 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int>A(N-1);
  for(int i  =0;i<N-1;i++){
    cin >> A[i];
  }
  vector<long long> inv(N);
  inv[1]=1;
  for(int i =2;i<N;i++){
    inv[i] = MOD- inv[MOD%i]*(MOD/i)%MOD; 
  }
  vector<long long>dp(N);
  dp[N-1] =0;
  vector<long long> sum(N+1);
  sum[N-1]=0;
  for(int i  =N-2; i>=0;i--){
    dp[ i] = ((sum[i+1]-sum[i+A[i]+1]+MOD+1)%MOD *inv[A[i]] +1)%MOD;
    sum[i] = (sum[i+1]+dp[i])%MOD;
  }
  cout<<dp[0]<<endl;

}
