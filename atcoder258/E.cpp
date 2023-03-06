#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q,x;
  cin >> n >> q>>x;
  vector<long long> w(n);
  for(int i  =0 ;i<n;i++){
    cin >> w[i];
  }
  vector<long long> pref(n+1);

  for(int i  =0 ; i<n;i++){
    pref[i+1] = pref[i]+w[i];
  }
  
  vector<int>to(n);
  vector<int>cnt(n);
  auto Get= [&](int id){
    return pref[n]*(id/n)+pref[id%n];
  };

  for(int i = 0; i<n;i++){
    int low= i+1;
    int high=i+x;
    while(low<high){
      int mid = (low+high)>>1;
      if(Get(mid) -pref[i] >=x){
        high=mid;
      }else {
        low=mid+1;
      }
    }
    to[i]  = low%n;
    cnt[i]  =low-i;
  }
  vector<int>was(n,-1);
  vector<int>pre(1,0);
  vector<int>period;

  was[0] = 0;
  while(true){
    pre.push_back(to[pre.back()]);
    if(was[pre.back()]!=-1){
      period = vector<int>(pre.begin()+(was[pre.back()]+1),pre.end());
      pre.resize(was[pre.back()]+1);
      break;
    }
    was[pre.back()] = (int)pre.size()-1;
  }
  while(q--){
    long long k;
    cin >>k;
    k-=1;
    int id;
    if(k<(int)pre.size()){
      id=pre[k];
    }else{
      k-=(int)pre.size();
      id= period[k%(int)period.size()];
    }
    cout<<cnt[id]<<endl;
  }
  

  return  0;
}

