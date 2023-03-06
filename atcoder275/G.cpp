#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const double INF = 1000000000000000000;
const double eps = 0.0000000001;
struct point{
  double x, y;
  point(double x, double y) : x(x),y(y){}
};
struct line{
  double a,b;
  line(){}
  line(double a, double b):a(a),b(b){}
};
bool is_paral(line l1, line l2){
  return abs(l1.a*l2.b-l2.a*l1.b)<eps;
}
bool is_under(point P, line L){
  return L.a*P.x+L.b*P.y <1;
}
point line_intersection(line l1, line l2){
  double d = l1.a*l2.b-l2.a*l1.b;
  return point((l2.b-l1.b)/d, (l1.a-l2.a)/d);
}
void solve() {
  int n;
  cin >>n;
  vector<int>A(n),B(n),C(n);
  for(int i =0;i<n;i++){
    cin >>A[i]>>B[i]>>C[i];
  }
  vector<pair<double, int>>P(n);
  for(int i=0;i<n;i++){
    P[i] =make_pair((double)B[i]/A[i],i);
  }
  sort(P.begin(),P.end());
  vector<line>L(n);
  for(int i =0;i<n;i++){
    int id =P[i].second;
    L[i].a= (double)A[id]/C[id];
    L[i].b= (double)B[id]/C[id];
  }
  vector<line>L2;
  L2.push_back(line(INF,10));
  L2.push_back(L[0]);
  for(int i=1;i<n;i++){
    if(is_paral(L2.back(), L[i]))
    {
      if(L2.back().a>L[i].a){
        L2.back()=L[i];
      }
    }else{
      L2.push_back(L[i]);
    }
  }
  L2.push_back(line(10,INF));
  n=L2.size();
  vector<int>H;
  H.push_back(0);
  for(int i=1;i<n;i++){
    while(H.size()>=2){
      int l1=H[H.size()-2];
      int l2=H[H.size()-1];
      int l3= i;
      point P = line_intersection(L2[l1], L2[l3]);
      if(!is_under(P,L2[l2])){
        H.pop_back();
      }else{
        break;
      }
    }
    H.push_back(i);
  }
  int cnt= H.size();
  double ans =10;
  for(int i =0;i<cnt-1;i++){
    point P =line_intersection(L2[H[i]], L2[H[i+1]]);
    ans =min(ans,P.x+P.y);
  }
  cout<<ans<<endl;

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<fixed<<setprecision(20);
  solve();
  return 0;
}
