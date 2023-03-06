#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b,c,d,e;
  cin >> a >> b>> c>> d>> e;
  map<int, int>m ;
  m[a]++, m[b]++, m[c]++, m[d]++;m[e]++;
  bool isok=true;
  if(m.size() !=2){
    isok=false;
  }else{

    if(m.begin()->second==2 || m.begin()->second==3){
      isok=true;
    }else{
      isok=false;

    }

  }
  if(isok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
  
  
  return 0;

}
