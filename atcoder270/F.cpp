#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000000;

struct unionfind{
  vector<int>p;
  unionfind(int n){
    p= vector<int>(n,-1);
  }
  int root(int x){
    if(p[x] <0){
      return x;
    }else{
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x)==root(y);
  }
  void unite(int x, int y){
    x=root(x);
    y=root(y);
    if(x!=y){
      if(p[x]<p[y]){
        swap(x,y);
      }
      p[y]+=p[x];
      p[x] =y;
    }
  }

};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int>X(n);
  for(int i=0;i<n;i++){
    cin >>X[i];
  }
  vector<int>Y(n);
  for(int i = 0; i<n;i++){
    cin >> Y[i];
  }
  vector<int>A(m), B(m), Z(m);
  for(int i=0;i<m;i++){
    cin >> A[i] >> B[i] >> Z[i];
    A[i]--;
    B[i]--;
  }
  vector<tuple<int,int,int>> E;
  for(int i =0;i<n;i++){
    E.push_back(make_tuple(X[i], i, n));
    E.push_back(make_tuple(Y[i],i, n+1));
  }
  for(int i = 0;i<m;i++){
    E.push_back(make_tuple(Z[i], A[i],B[i]));
  }
  sort(E.begin(), E.end());
  long long ans =INF;
  for(int i=0;i<4;i++){
    unionfind UF(n+2);
    long long sum=0;
    for(int j = 0;j<n*2+m;j++){
      int c= get<0>(E[j]);
      int u= get<1>(E[j]);
      int v= get<2>(E[j]);
      bool ok=true;
      if((i&1)==1 && v==n){
        ok=false;//1 3
      }
      if((i>>1&1)==1&& v==n+1){
        ok=false;//2 3
      }
      if(ok&& !UF.same(u,v)){
        UF.unite(u,v);
        sum+=c;
      }
    }
    bool ok=true;
    for(int j=1;j<n;j++){
      if(!UF.same(0,j)){
        ok=false;
      }
    }
    if(ok){
      ans =min(ans, sum);
    }
  }
  cout<<ans<<endl;
  return 0;
}
