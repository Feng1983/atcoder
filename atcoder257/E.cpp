#include <bits/stdc++.h>
using namespace std;

using ll  =long long;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  array<int,10> c;
  for(int i=1;i<=9;i++){
    cin >>c[i];
  }
  vector<int>f(n+1);
  for(int x=1;x<=9;x++){
    for(int i = c[x];i<=n;i++){
      f[i]  =max(f[i], f[i-c[x]]+1);
    }
  }
  while(f[n] >0){
    int x = 9;
    while(c[x] >n  || f[n-c[x]]!=f[n]-1){
      x--;
    }
    cout<<x;
    n-=c[x];
  }
  cout<<endl;

  return 0;

}
