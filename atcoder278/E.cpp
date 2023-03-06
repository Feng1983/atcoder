#include<bits/stdc++.h>

using namespace std;

void solve(){
  int H,W, N, h,w;
  cin >> H >> W >> N >> h >> w;
  vector<vector<int>> A(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  vector<vector<vector<int>>>S(N, vector<vector<int>>(H+1,vector<int>(W+1,0)));
  for(int i =0;i<H;i++){
    for(int j =0;j<W;j++){
      S[A[i][j]][i+1][j+1]++;
    }
  }

  for(int i=0;i<N;i++){
    for(int j=1;j<=H;j++){
      for(int k=1;k<=W;k++){
        S[i][j][k]+=S[i][j-1][k];
      }
    }
    for(int j=1;j<=H;j++){
      for(int k=1;k<=W;k++){
        S[i][j][k]+=S[i][j][k-1];
      }
    }
  }
  for(int i=0;i<=H-h;i++){
    for(int j=0;j<=W-w;j++){
      int ans =0;
      for(int k=0;k<N;k++){
        if(S[k][i+h][j+w]-S[k][i+h][j]-S[k][i][j+w]+S[k][i][j] <S[k][H][W]){
          ans++;
        }
      }
      cout<<ans;
      if(j<W-w){
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
  return 0;
}
