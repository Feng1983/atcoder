#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin >> n>>k;
  vector<int> a(n);
  for(int i=0 ; i<n;i++){
    cin >> a[i];
  }
  vector<int> b(k);
  for(int i = 0;i<k;i++){
    cin >> b[i];
    --b[i];
  }
  int mx = *max_element(a.begin(), a.end());
  set<int> idx;
  for(int i=0;i<n;i++){
    if(a[i]==mx){
      idx.insert(i);
    }
  }
  bool f=false;
  for(int i=0;i<k;i++){
    if(idx.count(b[i])){
    f=true;
    break;
    }
  }
  if(f){
    cout<<"Yes"<<endl;

  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
