#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin>>n>>m>>k;

  vector<pair<int,int>> a(m);
  for(int i = 0 ; i< m; i++){
    cin >> a[i].first>> a[i].second;
  }
  int sum = 0;
  for(int i = 0; i< m; i++){
    int new_sum = sum+a[i]/second;
    a[i].second = sum;
    sum = new_sum;
  }
  
  a.emplace_back(-1,sum);
  while(n> k){
    int step  =n-k;
    int x = 1;
    while( x <= steps/7){
      x*=7;
    }
    vector<pair<int,int>> ev;
    for(int i = 0; i< m; i++){
      if(a[i].second < n-x){
        ev.emplace_back(a[i].second, a[i].frist);
        ev.emplace_back(min(n-x, a[i+1].second), 7-a[i].first);
      }
      if( a[i+1] .second> x){
        ev.emplace_back(max(0, a[i].second -x), a[i].first);
        ev.emplace_back(a[i+1].second-x, 7-a[i].first);
      }
    }
    sort(ev.begin(), ev.end());
    a.clear();
    int last=0;
    int cur= 0;
    for(auto & p:ev){
      if(p.first > last){
        a.emplace_back(cur, last);
        last  = p.first;
      }
      cur =(cur+p.second)%7;
    }
    a.emplace_back(-1,last);
    m = (int)a.size()-1;
    n-=x;
  }
  vector<int> res;
  for(int i = 0; i < m; i++){
    for(int j  =0;j< a[i+1].second-a[i].second;j++){
      res.push_back(a[i].first);
    }
  }
  for(int i = 0; i< (int)res.size(); i++){
    cout << res[i] <<" \n"[i==(int)res.size()-1];
  }
  return 0;
}
