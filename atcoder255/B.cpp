#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
const double INF=1e6+5;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> A(k);
  for(int i=0;i<k;i++){
    cin >> A[i];
    --A[i];
  }
  vector<int> X(n), Y(n);
  for(int i=0;i<n;i++){
    cin >> X[i]>>Y[i];
  }
  cout<< fixed<< setprecision(20);
  double ans= 0.0;

  for(int  i=0;i<n;i++){
    double mx = INF;
    for(int t=0;t<k;t++){
      mx  =min(mx, hypot(X[i]-X[A[t]], Y[i]-Y[A[t]]));
    }
    ans = max(ans, mx);

  }
  cout<<ans<<endl;


  return 0;

}
