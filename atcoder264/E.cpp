#include <bits/stdc++.h>

using namespace std;

struct uf{
  vector<int> A, B;
  vector<int > p;

  uf(int N, int M){
    A.resize(N+M,0);
    B.resize(N+M,0);
    p.resize(N+M, -1);

    for(int i = 0;i <N;i++){
      A[i] =1;
    }
    for(int i = N;i<N+M;i++){
      B[i]=1;
    }
  }
  int root(int x){
    if(p[x]==-1){
      return x;
    }else{
      p[x] =root(p[x]);
      return p[x];
    }
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
  int getA(int x){
    return A[root(x)];
  }
  int getB(int x){
    return B[root(x)];
  }
  void unite(int x, int y){
    x =root(x);
    y=root(y);
    p[x] =y;
    A[y] +=A[x];
    B[y] +=B[x];
  }
};
void solve(){
  int n,m,e;
  cin >> n >> m >> e;
  vector<int>U(e),V(e);
  for(int i =0;i<e;i++){
    cin >> U[i] >> V[i];
    U[i]--;
    V[i]--;
  }
  int Q;
  cin >> Q;
  vector<int> X(Q);
  for(int i=0; i<Q;i++){
    cin >> X[i];
    X[i]--;
  }
  vector<bool> ok(e, true);
  for(int i=0;i <Q;i++){
    ok[X[i]] =false;
  }
  uf UF(n,m);
  int cnt=0;
  for(int i = 0;i<e;i++){
    if(ok[i]){
      if(!UF.same(U[i],V[i])){

        int ua =UF.getA(U[i]);
        int va =UF.getA(V[i]);
        int ub = UF.getB(U[i]);
        int vb = UF.getB(V[i]);
        if(ub >0 && vb==0){
          cnt+=va;
        }
        if(vb >0 && ub==0){
          cnt+=ua;
        }
        UF.unite(U[i],V[i]);
      }
    }
  }
  vector<int> ans(Q);
  for(int i = Q-1;i>=0;i--){
    ans[i] =cnt;
    if(!UF.same(U[X[i]],V[X[i]])){
      int ua =UF.getA(U[X[i]]);
      int va = UF.getA(V[X[i]]);
      int ub = UF.getB(U[X[i]]);
      int vb =  UF.getB(V[X[i]]);
      if(ub >0 && vb==0){
        cnt+=va;
      }
      if(vb>0 && ub==0){
        cnt+=ua;
      }
      UF.unite(U[X[i]], V[X[i]]);
    }
  }
  for(int i = 0;i<Q;i++){
    cout<<ans[i]<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  

}
