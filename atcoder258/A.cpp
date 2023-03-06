#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin  >> t;
  while(t--){
    int k;
    cin >> k;
    int h  =21+ k/60;
    int m  =k%60;
    cout<<h<<":"<<m/10<<m%10<<endl;

  }
  return 0;
}
