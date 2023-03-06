#include <bits/stdc++.h>
using namespace std;
const int mod = 999;
typedef long long  ll;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<ll>> f(n, vector<ll> (n));
  for(int i=n-1; i>=0;i--){
    for(int j = i; j<n;j++){
      if(i==j){
        f[i][j]=1;
        continue;
      }
      f[i][j]  =f[i+1][j];
      for(int k=i+2; k<=j; k++){
        if(p[k]> p[i+1]){
          f[i][j]+= f[k-1][j]*f[i+1][k-1];
        }
      }
    }
  }
   cout << f[0][n-1]<<endl;
   return 0;
}
