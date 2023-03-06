#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,s;
  cin >> n >> s;
  vector<int>a(n);
  for(int i = 0;i<n;i++){
    cin >>a[i];
  }
  vector<vector<int>>all(s+1);
  for(int i  =0;i<n;i++){
    all[a[i]].push_back(i);
  }
  auto DistToLeft=[&](long long i, int x){
    i%=n;
    auto it = lower_bound(all[x].begin(),all[x].end(),(int)i);
    if(it!=all[x].begin()){
      return i-(*prev(it));
    }
    return i-(all[x].back()-n);
  };
  auto DistToRight=[&](long long i,int x){
    i%=n;
    auto it =lower_bound(all[x].begin(), all[x].end(),(int)i);
    if(it!=all[x].end()){
      return (*it)-i;
    }
    return (all[x][0]+n)-i;
  };
  vector<vector<int>>cand(s+1);
  for(int i=1;i<=s;i++){
    cand[i].push_back(i);
  }
  vector<long long>dp(s+1);
  dp[0]=0;
  for(int i =1;i<=s;i++){
    long long p= dp[i-1];
    vector<int>vs;
    for(int x: cand[i]){
      long long pos =p-DistToLeft(p,  x);
      if(pos>=dp[i-x]){
        int low=1;
        int high=x;
        while(low<high){
          int mid=(low+high)>>1;
          if(pos >=dp[i-mid]){
            high=mid;
          }else{
            low=mid+1;
          }
        }
        int wait=x-low+1;
        if(i+wait <=s){
          cand[i+wait].push_back(x);
        }
        continue;
      }
      vs.push_back(x);
    }
    dp[i]=p;
    for(int x: vs){
      long long pos =p+DistToRight(p, x);
      dp[i] =max(dp[i],pos+1);
      if(i+x<=s){
        cand[i+x].push_back(x);
      }
    }
  }
  cout<<dp[s]<<endl;
  return 0;

}
