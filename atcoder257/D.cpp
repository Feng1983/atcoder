#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int>x(n),y(n), p(n);
  for(int i  = 0 ; i<n;i++){

    cin >> x[i]>>y[i]>>p[i];
  }
  vector<vector<long long>>w(n,vector<long long>(n));
  for(int i  =0 ; i<n;i++){
    for(int j  =0;j<n;j++){
      w[i][j] = (1LL* abs(x[i]-x[j])+abs(y[i]-y[j])+p[i]-1)/p[i];
    }
  }
  long long ans = 1e18;
  for(int s = 0 ;s<n;s++){
    long long res=0;
    vector<bool>vis(n);
    vector<long long> f(n,1e18);
    f[s]=0;
    for(int i = 0 ;i<n;i++){
      int x = -1;
      for(int  j = 0; j<n;j++){
        if(!vis[j]&& (x==-1|| f[j] <f[x])){
          x=j;
        }
      }
      vis[x] =true;
      res =max(res, f[x]);
      for(int  j =0;j<n;j++){
        f[j] = min(f[j], w[x][j]);
      }
    }
    ans =min(ans, res);
  }
  cout<<ans<<endl;

  return 0;

}
