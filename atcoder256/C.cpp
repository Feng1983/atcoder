#include <bits/stdc++.h>
using namespace std;

int h1,h2,h3, w1,w2,w3,ans,a[10][10];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>> h1>>h2>>h3>>w1>>w2>>w3;
  if(h1+h2+h3!=w1+w2+w3){
    cout<<0<<endl;
    return 0;
  }
  for(a[1][1]=1;a[1][1]<=30;a[1][1]++)
    for(a[1][2]=1;a[1][2]<=30;a[1][2]++)
      for(a[2][1]=1;a[2][1]<=30;a[2][1]++)
        for(a[2][2]=1;a[2][2]<=30;a[2][2]++){
          a[1][3] =h1-a[1][1]-a[1][2];
          a[2][3] = h2-a[2][1]-a[2][2];
          a[3][1]= w1-a[1][1]-a[2][1];
          a[3][2]=w2-a[1][2]-a[2][2];
          a[3][3]= w3-a[1][3]-a[2][3];
          bool ret=1;
          for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
              ret&=a[i][j]>0;
              ans+=ret;
            }
          }
        }
  cout<<ans<<endl;

  return 0;

}
