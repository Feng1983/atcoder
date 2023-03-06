#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
    long long b, k, sx, sy, fx, fy;
    cin >>b >> k >> sx>>sy>>fx>>fy;
    long long ans =(abs(sx-fx)+abs(sy-fy))*k;

    for(int ds = 0;ds<4;ds++){
      for(int df=0;df<4;df++){
        long long cur = 0;
        auto Go=[&](long long x, long long y,int dir){
          if(dir==0){
            cur+= x%b*k;
            x-= x%b;
          }
          if(dir==1){
            cur+=y%b*k;
            y-=y%b;
          }
          if(dir==2){
            cur+=(b-x%b)*k;
            x+=b-x%b;
          }
          if(dir==3){
            cur+=(b-y%b)*k;
            y+= b-y%b;
          }
          return make_pair(x,y);
        };
        auto Test=[&](long long u, long long v){
          if(u/b==v/b){
            cur+=min(min(u%b, v%b),min(b-u%b,b-v%b))*2;
          }
        };
        auto [px,py] = Go(sx,sy,ds);
        auto [qx,qy] =Go(fx,fy, df);
        cur+= abs(px-qx)+abs(py-qy);
        if(py!=qy){
          Test(px,qx);
        }
        if(px!=qx){
          Test(py,qy);
        }
        ans =min(ans,cur);
      }
    }
    cout<<ans<<endl;
  }

  return  0;
}

