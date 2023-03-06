#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,S;
  cin >> n >>S;
  vector<int> a(n),b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i]>>b[i];
  }
  vector<vector<bool>> dp(n+1,vector<bool>(S+1,false));
  dp[0][0] = true;
  for(int i = 0;i<n;i++){
    for(int j =0;j<=S;j++){
      if(dp[i][j]){
        if(j+a[i] <=S){
          dp[i+1][j+a[i]]=true;
        }
        if(j+b[i] <=S){
          dp[i+1][j+b[i]] =true;
        }
      }

    }
  }
  if(!dp[n][S]){
    cout<<"No"<<endl;
  }else{
    vector<char> ans(n);
    int s=S;
    for(int i  =n-1;i>=0;i--){
      bool ok = false;
      
      if(s>=a[i]){
        if(dp[i][s-a[i]]){
          ok=true;
        }
      }
      if(ok){
        ans[i]='H';
        s-=a[i];
      }else{
        ans[i] ='T';
        s-=b[i];
      }
    }
    cout<<"Yes"<<endl;
    for(int i =0;i<n;i++){
      cout<<ans[i];
    }
    cout<<endl;
  }

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
