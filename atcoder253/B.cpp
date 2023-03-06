#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i = 0; i<h;i++){
   cin >> s[i];
  }
  int xa=-1, ya=-1, xb=-1, yb=-1;
  for(int i=0;i< h;i++){
    for(int j =0;j<w;j++){
      if(s[i][j]=='o'){
        if(xa==-1){
          xa=i, ya=j;
        }else{
          xb=i, yb=j;
        }
      }
    }
  }
  cout<<abs(xa-xb)+abs(ya-yb)<<endl;


  return 0;
}
