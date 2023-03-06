#include <bits/stdc++.h>

using namespace std;

void solve(){
  int h1, w1;
  int h2, w2;
  cin >> h1>> w1;
  vector<vector<int>>A(h1, vector<int>(w1));
  for(int i  =0; i<h1;i++){
    for(int j=0;j<w1; j++){
      cin >> A[i][j];
    }
  }
  cin >>h2>>w2;
  vector<vector<int>>B(h2, vector<int>(w2));
  for(int i =0;i <h2;i++){
    for(int j  =0;j<w2;j++){
      cin >> B[i][j];
    }
  }
  bool  ok=false;
  for(int i =0;i<(1<<h1);i++){
    for(int j =0;j<(1<<w1);j++){
      if(__builtin_popcount(i)==h2 && __builtin_popcount(j)==w2){

        int c1=0;
        vector<int>r(h1,-1);
        for(int k = 0;k<h1;k++){
          if((i>>k &1)==1){
            r[k] =c1;
            c1++;
          }
        }
        int c2 =0;
        vector<int>c(w1, -1);
        for(int k=0; k<w1;k++){
          if((j>>k&1) ==1){
            c[k] = c2;
            ++c2;
          }
        }
        bool ok2 =true;
        for(int k=0;k<h1;k++){
          for(int l = 0;l<w1;l++){
            if(r[k]!=-1 &&c[l]!=-1){
              if(A[k][l] != B[r[k]][c[l]]){
                ok2=false;
              }
            }
          }
        }
        if(ok2){
          ok=true;
        }
      }
    }
  }
  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  

}
