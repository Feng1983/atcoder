#include <bits/stdc++.h>

using namespace std;
const long long MOD= 998244353;
template<typename T>
struct invertible_binary_indexed_tree{

  int N;
  vector<T> dp;
  function <T(T,T)> f;
  function<T(T)>inv;

  T E;
  invertible_binary_indexed_tree(int N,function<T(T,T)>f, function<T(T)>inv, T E):N(N),dp(N+1,E),f(f),inv(inv), E(E){}

  void add(int i, T  x){
    i++;
    while(i<=N){
      dp[i]  =f(dp[i],x);
      i+=i&-i;
    }
  }
  T sum(int i){
    T ans =E;
    while(i>0){
      ans =f(ans, dp[i]);
      i-=i&-i;
    }
    return ans;
  }
  T sum(int l ,int r){
    return f(sum(r), inv(sum(l)));
  }
  T operator[](int i){
    return sum(i,i+1);
  }
};
long long add(long long x, long long y){
  return (x+y)%MOD;
}
long long neg(long long x){
  return (MOD-x)%MOD;
}
void solve() {
  int N, K, C;
  cin >> N >> K >> C;
  invertible_binary_indexed_tree<long long>dp(N+K-1,  add,  neg, 0);
  dp.add(N+K-2, C);
  for(int i=1;i<N;i++){
    dp.add(N-i,dp.sum(N-i+1,N-i+K-1));
    dp.add(N-i-2+K, dp[N-i+K-1]);
    dp.add(N-i, dp[N-i+K-1]*(C-1));
  }
  cout<<dp.sum(0,K)<<endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
