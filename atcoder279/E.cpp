#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
void solve() {
  int n ,m;
  cin >> n >> m;
  vector<int>A(m);
  for(int i=0;i<m;i++){
    cin >> A[i];
    A[i]--;
  }
  vector<int>B(n);
  for(int i=0;i<n;i++){
    B[i]  =i;
  }
  vector<int>X(m), Y(m);
  for(int i =0;i<m;i++){
    X[i]  =B[A[i]];
    Y[i]  =B[A[i]+1];
    swap(B[A[i]],B[A[i]+1]);
  }
  vector<int>P(n);
  for(int i=0;i<n;i++){
    P[B[i]] =i;
  }
  for(int i =0;i<m;i++){
    if(X[i]!=0 && Y[i]!=0){
      cout<<P[0]+1<<endl;
    }else{
      cout<<P[X[i]+Y[i]]+1<<endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
