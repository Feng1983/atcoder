#include<bits/stdc++.h>
using namespace std;


int main(){
  
  ios::sync_with_stdio(false);
  cin.tie(0);
 int a, b, c; 
  cin >> a>> b>> c;
  vector<int> v= {a,b,c};
  sort(v.begin(), v.end());
  if(b==v[1]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
