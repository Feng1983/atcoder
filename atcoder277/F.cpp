#include <bits/stdc++.h>
#include <tuple>
#include <utility>
using namespace std;
const int INF = 1000000000;
void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> A(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> A[i][j];
    }
  }
  vector<int> mx(h, -INF), mn(h, INF);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (A[i][j] != 0) {
        mx[i] = max(mx[i], A[i][j]);
        mn[i] = min(mn[i], A[i][j]);
      }
    }
  }
  vector<pair<int,int>> P;
  for(int i =0;i<h;i++){
    if(mx[i]!=-INF){
      P.push_back(make_pair(mn[i], mx[i]));
    }
  }
  sort(P.begin(),P.end());
  int cnt= P.size();
  bool ok  =true;
  for(int i =0;i<cnt-1;i++){
    if(P[i].second>P[i+1].first){
      ok=false;
    }
  }
  vector<vector<int>> E(w);
  int v= w;
  for(int i =0;i<h;i++){
    vector<pair<int,int>>  B;
    for(int j=0;j<w;j++){
      if(A[i][j]!=0){
        B.push_back(make_pair(A[i][j],j));
      }
    }
    int sz =B.size();
    if(sz >0){
      sort(B.begin(),B.end());
      vector<vector<int>>B2;
      B2.push_back(vector<int>(1,B[0].second));
      for(int j =1;j<sz;j++){
        if(B[j].first !=B[j-1].first){
          B2.push_back(vector<int>(1,B[j].second));
        }else{
          B2.back().push_back(B[j].second);
        }
      }
      int sz2=B2.size();
      for(int j=0;j<sz2-1;j++){
        E.push_back(vector<int>(0));
      }
      for(int j =0;j<sz2-1;j++){
        int c1=B2[j].size();
        for(int k=0;k<c1;k++){
          E[B2[j][k]].push_back(v+j);
        }
        int c2=B2[j+1].size();
        for(int k=0;k<c2;k++){
          E[v+j].push_back(B2[j+1][k]);
        }
      }
      v+=sz2-1;
    }
  }
  vector<int> in(v,0);
  for(int i=0;i<v;i++){
    for(int j:E[i]){
      in[j]++;
    }
  }
  queue<int>Q;
  for(int i=0;i<v;i++){
    if(in[i]==0){
      Q.push(i);
    }
  }
  while(!Q.empty()){
    int v =Q.front();
    Q.pop();
    for(int w: E[v]){
      in[w]--;
      if(in[w]==0){
        Q.push(w);
      }
    }
  }
  for(int i=0;i<v;i++){
    if(in[i] >0){
      ok=false;
    }
  }
  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
