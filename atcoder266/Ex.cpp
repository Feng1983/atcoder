#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

using i64=long long;

int main(){
  int n;
  cin >> n;
  vector<array<int, 4>> a(n);
  for(int i = 0 ; i< n;i++){
    int t, x, y, v;
    cin >> t >> x >> y >> v;
    a[i]  ={y, t+x-y, t-x-y, v};
  }
  sort(a.begin(),a.end());
  vector<int> vx(n);
  for(int i = 0; i<n;i++){
    auto [_, x,y,v] =a[i];
    vx[i] = x;
  }
  sort(vx.begin(), vx.end());
  i64 ans= 0;
  vector<map<int, i64>>f(n);
  auto query =[&] (int x, int y){
    i64 ans =0;
    for(int i = x+1;i;i-=i&-i){
      auto &s = f[i-1];
      auto it  = s.upper_bound(y);
      if(it!=s.begin()){
        ans =max(ans, prev(it)->second);
      }
    }
    return ans;
  };
  auto add = [&](int x, int y, i64 v){
    for(int i =x+1;i<=n;i+=i&-i){
      auto & s =f[i-1];
      auto it=  s.upper_bound(y);
      if(it!=s.begin() && prev(it)->second >= v){
        continue;
      }
      s[y]  =v;
      it = s.find(y);
      while(next(it)!= s.end()&&next(it)->second <=v){
        s.erase(next(it));
      }
    }
  };
  for(auto [_, x,y,v]:a){
    if(x<0 || y<0){
      continue;
    }
    x =lower_bound(vx.begin(), vx.end(),x)-vx.begin();
    i64 s =  v+ query(x,y);
    add(x,y,s);
    ans =max(ans, s);
  }
  cout<<ans<<endl;

  return 0;
}
