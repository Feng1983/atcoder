#include<bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000;

void solve(){
  int n, m, k;
  cin >> n >> m >>k;
  vector<int>A(m),B(m),C(m);
  for(int i = 0; i<m;i++){
    cin >> A[i] >> B[i] >>C[i];
    A[i]--;B[i]--;
  }
  vector<int>E(k);
  for(int i=0;i<k;i++){
    cin >> E[i];
    --E[i];
  }
  vector<long long>dp(n, INF);
  dp[0] = 0;
  for(int i = 0;i<k;i++){
    dp[B[E[i]]] = min(dp[B[E[i]]], dp[A[E[i]]]+C[E[i]]);
  }
  if(dp[n-1]==INF){
    cout<<-1<<endl;
  }else{
    cout<<dp[n-1]<<endl;
  }

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
