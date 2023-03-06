#include<bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<long long>A(n);
  for(int i =0;i<n;i++){
    cin >>A[i];
  }
  long long tv=inf, fv=0;
  while(tv-fv>1){
    long long mid =(tv+fv)/2;
    long long ans =0;
    for(int i = 0;i<n;i++){
      if(i<mid%n){
        ans+=min(A[i], mid/n+1);
      }else{
        ans+=min(A[i], mid/n);
      }
    }
    if(ans >=k){
      tv=mid;
    }else{
      fv=mid;
    }
  }
  for(int i =0;i<n;i++){
    if(i<tv%n){
      A[i]-=min(A[i], tv/n+1);
    }else{
      A[i]-=min(A[i], tv/n);
    }
  }
  for(int i=0;i<n;i++){
    cout<<A[i] <<" \n"[i==n-1];
  }
  return 0;

}
