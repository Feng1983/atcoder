#include<bits/stdc++.h>
using namespace std;

void solve(){

  int n,m;
  cin >> n >> m;
  vector<int>A(n);
  for(int i = 0;i<n;i++){
    cin >> A[i] ;
  }
  sort(A.begin(), A.end());
  long long sum  =0;
  for(auto x: A){
    sum+=x;
  }
  vector<int> P;
  for(int i = 0;i<n;i++){
    int j  =(i+n-1)%n;
    if(A[j] !=(A[i]+m-1)%m && A[j]!=A[i]){
      P.push_back(i);
    }
  }
  if(P.empty()){
    cout<<0<<endl;
  }
  else{
    int cnt=P.size();
    long long mx =0;
    for(int i=0;i<cnt;i++){
      int r =P[(i+1)%cnt];
      if(i==cnt-1){
        r+=n;
      }
      long long tmp =0;
      for(int j = P[i];j<r;j++){
        tmp+=A[j%n];
      }
      mx = max(mx, tmp);
    }
    cout<<sum-mx<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
