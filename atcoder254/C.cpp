#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n ,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  for(int b=0;b<k;b++){
    vector<int> c;
    for(int i=b;i<n;i+=k){
      c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    for(int i = b;i<n;i+=k){
      a[i]  =c[(i-b)/k];
    }
  }
  if(is_sorted(a.begin(),a.end())){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }


  return 0;
}
