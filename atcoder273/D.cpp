#include<bits/stdc++.h>
using namespace std;


void solve(){
  int H,W, rs,cs;
  cin >> H >>W>> rs>> cs;
  rs--;
  cs--;
  int n;
  cin >> n;
  vector<int>r(n),c(n);
  for(int i  =0;i<n;i++){
    cin >>r[i]>>c[i];
    r[i]--;c[i]--;
  }
  map<int,set<int>>R,C;
  for(int i=0;i<n;i++){
    R[c[i]].insert(r[i]);
    C[r[i]].insert(c[i]);
  }
  int Q;
  cin >> Q;
  while(Q--){
    char d;
    int l;
    cin >> d >> l;
    if(d=='L'){
      auto itr=C[rs].lower_bound(cs);
      if(itr==C[rs].begin()){
        cs=max(cs-l,0);
      }else{
        cs =max(cs-l,*prev(itr)+1);
      }
    }
    if(d=='R'){
      auto itr= C[rs].lower_bound(cs);
      if(itr==C[rs].end()){
        cs =min(cs+l, W-1);
      }else{
        cs =min(cs+l, *itr-1);
      }
    }
    if(d=='U'){
      auto itr= R[cs].lower_bound(rs);
      if(itr==R[cs].begin()){
        rs =max(rs-l,0);

      }else{
        rs = max(rs-l,*prev(itr)+1);
      }
    }
    if(d=='D'){
      auto itr = R[cs].lower_bound(rs);
      if(itr==R[cs].end()){
        rs= min(rs+l, H-1);
      }else{
        rs = min(rs+l, *itr-1);
      }
    }
    cout<<(rs+1)<<' '<<(cs+1)<<endl;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;

}
