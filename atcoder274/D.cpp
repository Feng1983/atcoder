#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int x,y;
  cin >>x>>y;
  vector<int>A(n);
  for(int i  =0;i<n;i++){
    cin >>A[i];
  }
  bitset<20001>dp1,dp2;
  dp1.set(10000+A[0]);
  dp2.set(10000);
  for(int i  =1;i<n;i++){
    if(i%2==1){
      dp2=(dp2<<A[i])|(dp2>>A[i]);
    }else{
      dp1=(dp1<<A[i])|(dp1>>A[i]);
    }
  }
  if(dp1[10000+x]==1&& dp2[10000+y]==1){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }

  return  0;
}
