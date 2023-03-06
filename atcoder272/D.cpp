#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n, m;
  cin >> n >> m;
  vector<int>dx, dy;
  int cnt=0;
  for(int i=0;i*i<=m;i++){
    int tv=0, fv=10000;
    while(fv-tv>1){
      int mid =(tv+fv)/2;
      if(mid*mid<=m-i*i){
        tv=mid;
      }else{
        fv=mid;
      }
    }
    if(tv*tv==m-i*i){
      cnt++;
      dx.push_back(i);
      dy.push_back(tv);
    }
  }
  vector<vector<int>>d(n, vector<int>(n,-1));
  d[0][0]=0;
  queue<pair<int,int>>Q;
  Q.push(make_pair(0,0));
  while(!Q.empty()){
    int x =Q.front().first;
    int y =Q.front().second;
    Q.pop();
    for(int i=0;i<cnt;i++){
      for(int j =-1;j<=1;j+=2){
        for(int k=-1;k<=1;k+=2){
          int x2=x+dx[i]*j;
          int y2=y+dy[i]*k;
          if(0<=x2 && x2<n && 0<=y2 &&y2<n){
            if(d[x2][y2]==-1){
              d[x2][y2]=d[x][y]+1;
              Q.push(make_pair(x2,y2));
            }
          }
        }
      }
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout<<d[i][j];
      if(j<n-1){
        cout<<' ';
      }
    }
    cout<<endl;
  }

}
int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return  0;
}
