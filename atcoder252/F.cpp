#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long l;
  cin >> n >> l;
  vector<long long > a;
  for(int i = 0; i< n;i++){
    cin >> a[i];
  }
  multiset<long long> s(a.begin(), a.end());
  auto sum = accumulate(a.begin(), a.end(),0LL);
  if(sum < l){
    s.insert(l-sum);
  }

  long long ans=0;
  while(s.size() > 1){
    auto x= *s.begin();
    s.erase(s.begin());
    auto y = *s.begin();
    s.erase(s.begin());
    ans+=x+y;
    s.insert(x+y);
  }
  cout << ans <<endl;
  return 0;
}
