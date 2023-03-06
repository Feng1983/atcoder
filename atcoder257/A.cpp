#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x ;
  cin >> n >> x;
  --x;
  cout<<char('A'+(x/n))<<endl;

  return 0;

}
