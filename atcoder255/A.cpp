#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;
  vector<vector<int>> p(2, vector<int>(2));
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
       cin >> p[i][j];
    }
  }
  r--, c--;
  cout<<p[r][c]<<endl;
  return 0;

}
