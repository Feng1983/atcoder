#include<bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000;

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for(int i = 0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  vector<map<int,int>> mp1(n);
  for(int i =0;i<(1<<(n-1));i++){
    int X=a[0][0];
    int x =0, y=0;
    for(int j=0;j<n-1;j++){
      if((i>>j&1)==1){
        x++;
      }else{
        y++;
      }
      X^=a[x][y];
    }
    mp1[x][X]++;
  }
  vector<map<int,int>>mp2(n);
  for(int i=0;i<(1<<(n-1));i++){
    int X=a[n-1][n-1];
    int x= n-1,y=n-1;
    for(int j =0;j<n-1;j++){
      if((i>>j&1)==1){
        x--;
      }else{
        y--;
      }
      X^=a[x][y];
    }
    mp2[x][X]++;
  }
  long long ans =0;
  for(int i = 0 ;i<n;i++){
    for(auto P:mp1[i]){
      if(mp2[i].count(P.first^a[i][n-1-i])==1){
        ans+=(long long)P.second*mp2[i][P.first^a[i][n-1-i]];
      }
    }
  }
  cout<<ans<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
