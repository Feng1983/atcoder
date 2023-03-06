#include <bits/stdc++.h>
using namespace std;
template <typename T> class fenwick {
public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) { fenw.resize(n); }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<array<int, 4>> qs(q);
  vector<int> when(n, 0);
  vector<int> what(n, 0);
  vector<long long> res(q, -1);
  vector<vector<pair<int,int>>> ask(q);

  fenwick<long long> fenw(m);
  for(int i=0;i<q; i++){
    auto& p  =qs[i];
    cin >> p[0] >> p[1] >> p[2];
    if(p[0]==1){
      cin >> p[3];
      --p[1],--p[2];
      fenw.modify(p[1],p[3]);
      fenw.modify(p[2]+1, -p[3]);
    }else{
      if(p[0]==2){
        --p[1];
        when[p[1]]=i;
        what[p[1]]= p[2];
      }else{
        --p[1];--p[2];
        res[i]  = what[p[1]]+fenw.get(p[2]);
        ask[when[p[1]]].emplace_back(p[2],i);
      }
    }
  }
  fenwick<long long> fenw2(m);
  for(int i=0;i<q;i++){
    for(auto &p: ask[i]){
      res[p.second] -= fenw2.get(p.first);
    }
    auto& p = qs[i];
    if(p[0]==1){
      fenw2.modify(p[1], p[3]);
      fenw2.modify(p[2]+1, -p[3]);
    }
  }
  for(int i=0;i<q;i++){
    if(qs[i][0]==3){
      cout<<res[i]<<endl;
    }
  }

  return 0;
}
