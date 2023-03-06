#include<bits/stdc++.h>
using namespace std;


 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i =0;i<n;i++){
    cin >> a[i];
    --a[i];
  }
  int t= 0;
  long long ans = 0;
  for(int i=0;i<n;i++){
    if(a[i]==i){
      t++;
    }else if(a[a[i]] == i){
      ans++;
    }
  }
  ans/=2;
  if(t>1){
    ans+=1LL*t*(t-1)/2;
  }
  cout<<ans<<endl;


  return 0;
}

