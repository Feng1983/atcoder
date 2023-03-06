#include<bits/stdc++.h>
using namespace std;

void solve(){
  int H, W;
  cin >> H>> W;
  vector<vector<char>> g(H, vector<char>(W));
  for(int i = 0 ;i<H; i++){
    for(int j=0;j<W;j++){
      cin >> g[i][j];
    }
  }

  int x=0,y=0;
  bool ok =true;
  for(int i =0;i<H*W;i++){
    char c = g[x][y];
    int x2=x, y2=y;
    if(c=='U'){
      x--;
    }
    if(c=='D'){
      x++;
    }
    if(c=='L'){
      y--;
    }
    if(c=='R'){
      y++;
    }
    if(x<0 || x>=H || y< 0 || y>= W){
      ok=false;
      cout<<x2+1<<' '<<y2+1<<endl;
      break;
    }
  }
  if(ok){
    cout<<-1<<endl;
  }
}

int main(){
  solve();

  return 0;

}
