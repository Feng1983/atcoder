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

  int sx, sy, tx, ty, a,b,c,d;
  cin >> sx >>sy;
  cin >> tx >> ty;
  cin >> a >> b>> c >> d;
  vector<pair<int,int>> ans;
  if((sx-tx)%2!=0 || (sy-ty)%2!=0){
    cout<<"No"<<endl;
    return 0;
  }
  auto move=[&](int x, int y){
    ans.emplace_back(x,y);
    sx  =2*x-sx;
    sy = 2*y-sy;
  };
  if(a==b && sx !=tx){
    move(a,c);
  }
  if(c==d && sy!=ty){
    move(a,c);
  }
  if(a==b){
    if(sx!=tx){
      cout<<"No"<<endl;
      return 0;
    }
  }else{
    while(sx<tx){
      move(a,c);
      move(a+1,c);
    }
    while(sx>tx){
      move(a+1,c);
      move(a,c);
    }
  }
  if(c==d){
    if(sy!=ty){
      cout<<"No"<<endl;
      return 0;
    }
  }else{
    while(sy<ty){
      move(a,c);
      move(a,c+1);
    }
    while(sy>ty){
      move(a,c+1);
      move(a,c);
    }
  }
  cout<<"Yes"<<endl;
  for(auto [x,y]:ans){
    cout<<x <<" "<<y<<endl;
  }
  return 0;
}
