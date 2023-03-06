#include "atcoder/maxflow.hpp"
#include <bits/stdc++.h>
#include<atcoder/maxflow>

using namespace std;

const int INF = 1000000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h,w;
  cin >> h>>w;
  vector<vector<char>>g(h,vector<char>(w));
  for(int i  =0;i <h;i++){
    for(int j =0;j<w;j++){
      cin >>g[i][j];
    }
  }
  vector<vector<int>> id(h,vector<int>(w,-1));
  int n=0;
  for(int i=0;i<h;i++)
  {
    for(int j =0;j<w;j++){
      if(g[i][j]=='.'){
        id[i][j]=n;n++;
      }
    }
  } 
  
  atcoder::mf_graph<int>G(n*2+2);
  for(int i =0;i<n;i++){
    G.add_edge(n*2, i*2, 1);
    G.add_edge(i*2,i*2+1,INF);
    G.add_edge(i*2+1,n*2+1,1);
  }
  int cnt=0;
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w-1;j++){
      if(g[i][j]=='.' && g[i][j+1]=='.'){
        int a=id[i][j];
        int b=id[i][j+1];
        cnt++;
        G.add_edge(a*2,n*2+1,1);
        G.add_edge(b*2,a*2,1);
      }
    }
  }
  for(int i=0;i<h-1;i++){
    for(int j=0;j<w;j++){
      if(g[i][j]=='.' && g[i+1][j]=='.'){
        int a=id[i][j];
        int b=id[i+1][j];
        cnt++;
        G.add_edge(n*2,a*2+1,1);
        G.add_edge(a*2+1,b*2+1,1);
      }
    }
  }
  cout<<G.flow(n*2,n*2+1)-cnt<<endl;
  return 0;
}
