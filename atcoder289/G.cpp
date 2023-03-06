#include<bits/stdc++.h>
using namespace std;

using i64=long long;
using T = __int128;

struct Point {
    T x;
    T y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    
    Point &operator+=(const Point &p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point &operator*=(const T &v) {
        x *= v, y *= v;
        return *this;
    }
    friend Point operator-(const Point &p) {
        return Point(-p.x, -p.y);
    }
    friend Point operator+(Point lhs, const Point &rhs) {
        return lhs += rhs;
    }
    friend Point operator-(Point lhs, const Point &rhs) {
        return lhs -= rhs;
    }
    friend Point operator*(Point lhs, const T &rhs) {
        return lhs *= rhs;
    }
};

T dot(const Point& a, const Point& b){
  return a.x*b.x+a.y*b.y;
}

T cross(const Point& a, const Point& b){
  return a.x*b.y-a.y*b.x;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  sort(b.begin(),b.end(), greater());
  vector<Point>h;
  for(int i =0;i<n;i++){
    Point p(i+1,1LL*(i+1)*b[i]);
    while(h.size()>1  && cross(h.back()-h.end()[-2], p-h.back())>=0){
      h.pop_back();
    }
    h.push_back(p);
  }
  for(int i=0;i<m;i++){
    int c;
    cin >> c;
    Point p(c,1);
    int lo=0, hi=h.size()-1;
    while(lo<hi){
      int m  =(lo+hi)/2;
      if(dot(h[m], p) <dot(h[m+1],p)){
        lo=m+1;
      }else{
        hi= m;
      }
    }
    i64 ans = dot(h[lo],p);//n*price+n*b[i]*1
    cout<<ans<<" \n"[i==m-1];
  }
  return 0;
}
