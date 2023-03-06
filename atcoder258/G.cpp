#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  const int N = 3010;
  vector<bitset<N>> b(n);
  vector<string> s(n);
  for(int i  =0;i<n;i++){
    cin >>s[i];
    for(int j=0;j<n;j++){
      if(s[i][j]=='1'){
        b[i][j]=1;
      }
    }
  }

  long long ans=0;
  for(int i= 0 ;i<n;i++){
    for(int j = i+1;j<n;j++){
      if(s[i][j]=='1'){
        ans+=(b[i]&b[j]).count();
      }
    }
  }
  cout<<ans/3<<endl;
  return 0;
}
