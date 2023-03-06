#include<bits/stdc++.h>
using namespace std;

void solve(){
  int N, M, T;
  cin >> N >> M >> T;
  vector<int>A(N-1);
  for(int i =0;i<N-1;i++){
    cin >> A[i];
  }
  vector<int> X(M), Y(M);
  for(int i = 0;i<M;i++){
    cin >> X[i] >>Y[i];
    X[i]--;
  }
  vector<int>B(N,0);
  for(int i=0;i<M;i++){
    B[X[i]] +=Y[i];
  }
  long long  t=T;
  bool ok =true;
  for(int i = 0;i<N-1;i++){
    if(t<=A[i]){
      ok=false;
    }
    t-=A[i];
    t+=B[i+1];
  }
  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}

int main(){
  solve();

  return 0;

}
