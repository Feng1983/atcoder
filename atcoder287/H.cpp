#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int MAXN = 2000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<bitset<MAXN>>f(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    a--, b--;
    f[a][b]=1;
  }
  int Q;
  cin >> Q;
  vector<int> s(Q), t(Q), ans(Q,-1);
  for(int i =0; i< Q; i++){
    cin >> s[i] >> t[i];
    s[i]--,t[i]--;
  }
  for(int k=0;k<N;k++){
    f[k][k]  =1;
    for(int i=0;i<N;i++){
      if(f[i][k] )f[i]|= f[k];
    }
    for(int i =0;i <Q;i++){
      if(ans[i] ==-1&& k  >= max(s[i],t[i]) && f[s[i]][t[i]]){
        ans[i]  =k+1;
      }
    }
  }
  for(int i = 0;i<Q;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
