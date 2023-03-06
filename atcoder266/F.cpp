#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& E, vector<int>&d,vector<int>&p, vector<vector<int>>& c, vector<int>&in , int v){
  in.push_back(v);
  for(auto w: E[v]){
    if(d[w]==-1){
      d[w]= d[v]+1;
      p[w]=v;
      c[v].push_back(w);
      dfs(E,d, p, c, in, w);
    }
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for(int i  =0;i<n;i++){
    int u, v;
    cin >> u >> v;
    --u,--v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> p(n,-1);
  vector<vector<int>>c(n);
  vector<int>d(n,-1);
  vector<int>imos(n,0);
  vector<int>in;
  for(int i  =0;i <n;i++){
    if(d[i]==-1){
      d[i] =0;
      if(i>0){
        p[i] = 0;
        c[0].push_back(i);
        d[i] =1;
        imos[i]++;
        imos[0]--;
      }
      dfs(E ,d, p, c, in,i);
    }
  }
  for(int i = 0;i<n;i++){
    for(int j: E[i]){
      if(d[j] <d[i]-1){
        imos[i]++;
        imos[j]--;
      }
    }
  }
  reverse(in.begin(), in.end());
  for(int v: in){
    if(v!=0){
      imos[p[v]]+=imos[v];
    }
  }
  vector<vector<int>> pp(18, vector<int>(n,-1));
  pp[0] = p;
  vector<vector<int>> sum(18, vector<int>(n, 0));
  sum[0] =imos;
  for(int  i=0;i<18-1;i++){
    for(int j  =0;j<n;j++){
      if(pp[i][j]!=-1){
        pp[i+1][j] = pp[i][pp[i][j]];
        if(pp[i+1][j] !=-1){
          sum[i+1][j]  =sum[i][j]+sum[i][pp[i][j]];
        }
      }
    }
  }
  int Q;
  cin >> Q;
  for(int i =0;i<Q;i++){
    int x, y;
    cin >> x>> y;
    --x, --y;
    if(d[x] >d[y]){
      swap(x,y);
    }
    int s =0;
    for(int j =0;j<18;j++){
      if(((d[y]-d[x])>>j &1) ==1){
        s+=sum[j][y];
        y=pp[j][y];
      }
    }
    if(x!=y){
      for(int j =18-1;j>=0;j--){
        if(pp[j][x]!=pp[j][y]){
          s+=sum[j][x];
          s+=sum[j][y];
          x= pp[j][x];
          y=pp[j][y];
        }
      }
      s+=sum[0][x];
      s+=sum[0][y];
    }
    if(s==0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
 
  return 0;

}
