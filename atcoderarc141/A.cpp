#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<long long> nums(1, -1);
  for (int x = 1; x < (int)1e6; x++) {
    string w = to_string(x);
    string s = w + w + w;
    while (s.size() <= 18) {
      nums.push_back(atoll(s.c_str()));
      s += w;
    }
  }
  sort(nums.begin(), nums.end());
  int tt;
  cin >>tt;
  while(tt--){
    long long n;
    cin >> n;
    long long ans =*prev(upper_bound(nums.begin(), nums.end(),n));
    long long p10=1;
    for(int len=1;len<=9;len++){
      long long x = min(p10*10-1, n/(p10*10+1));
      if(x >=p10){
        ans=max(ans, x*(p10*10+1));
      }
      p10*=10;
    }
    cout<<ans<<endl;
  }
  return 0;
}
