#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }

  int ans = 0;
  for(int i = 0;i<n;i++){
    int x = accumulate(a.begin()+i,a.end(),0);
    if(x>=4){
      ans+=1;
    }
  }
  cout<<ans<<endl;
  return 0;

}
