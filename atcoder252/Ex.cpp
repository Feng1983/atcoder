#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, c;
  long long k;
  cin  >> n >> c>> k;
  vector<vector<long long>>a(c);
  for(int i = 0;i<n;i++){
    int d;
    long long v;
    cin >> d >> v;
    --d;
    a[d].push_back(v);
  }

  vector<int> order(c);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i,int j){
      return a[i].size() > a[j].size();
      });
  vector<int> p1, p2;
  {
    long long x=1, y=1;
    for(int i : order){
      if(x<=y){
        x*=a[i].size();
        p1.push_back(i);
      }else{
        y*=a[i].size();
        p2.push_back(i);
      }
      if(x > y){
        swap(p1,p2);
      }
    }
  }
  auto Make = [&](const vector<int>& v){
    vector<long long> ret;
    function<void(int ,long long)>Dfs=[&](int i, long long s){
      if(i==(int)v.size()){
        ret.push_back(s);
        return;
      }
      for(long long x: a[v[i]]){
        Dfs(i+1, s^x);
      }
    };
    Dfs(0,0);
    return ret;
  };
  auto x =Make(p1);
  auto y= Make(p2);
  k = (long long) x.size()* (long long)y.size()-k+1;
  auto Count = [&](long long num, int shift){
    long long ret= 0;
    gp_hash_table<long long, int, chash> mp;
    for(auto v: x){
      mp[v >>shift] +=1;
    }
    for(auto v: y){
      auto goal = (v >> shift)^num;
      auto it = mp.find(goal);
      if(it!=mp.end()){
        ret+=it->second;
      }
    }
    return ret;
  };
  long long pref = 0;
  for(int bit=59; bit>=0;bit--){
    auto got=Count(pref*2,bit);
    if(got <k){
      k-=got;
      pref = pref*2+1;
    }else{
      pref *=2;
    }
  }

  cout<<pref<<endl;
  return 0;
}
