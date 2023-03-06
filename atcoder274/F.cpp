#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

const double INF = 1000000000000000000;
struct frac{
  int x,y;
  friend bool operator<(const frac& l, const frac& r){

    return l.x*r.y<r.x*l.y;
  }

};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,a;
  cin >> n>>a;
  vector<array<int,3>>data(n);
  for(int i=0;i<n;i++){
    cin >>data[i][0]>>data[i][1]>>data[i][2];
  }
  frac zero={0,1};
  int ans =0;
  for(int i =0;i<n;i++){
    vector<pair<frac, int>>event;
    for(int j =0;j<n;j++){
      int x_diff =data[j][1]-data[i][1];
      int v_diff =data[j][2]-data[i][2];
      if(v_diff==0){
        if(0<=x_diff && x_diff<=a)event.push_back({zero,-data[j][0]});
      }else if(v_diff>0){
        frac start = {-x_diff,v_diff};
        event.push_back({start,-data[j][0]});
        frac end = {a-x_diff,v_diff};
        event.push_back({end,data[j][0]});
      }else {
        frac start= {x_diff-a,-v_diff};
        event.push_back({start,-data[j][0]});
        frac end = {x_diff,-v_diff};
        event.push_back({end,data[j][0]});
      }
    }
    sort(event.begin(), event.end());
    int crr=0;
    for(auto[t,val]:event){
      crr-=val;
      if(!(t<zero))ans =max(ans,crr);
    }
  }
  cout<<ans<<endl;


  return 0;
}
