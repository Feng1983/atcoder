#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int,int>>a(n);
  for(int i = 0; i<n;i++){
    cin >>a[i].first>>a[i].second;
  }
  sort(a.begin(),a.end());
  int j =1;
  for(int i =1;i<n;i++){
    if(a[i].first <=a[j-1].second){
      a[j-1].second = max(a[j-1].second, a[i].second);
    }else{
      a[j++]=a[i];
    }
  }
  for(int i = 0;i<j;i++){
    cout<<a[i].first<<" "<<a[i].second<<endl;
  }

  return 0;

}
