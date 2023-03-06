#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

map<i64, i64> mp;
i64 f(i64 n) {
  if (n == 0) {
    return 1;
  } else {
    if (mp.count(n) == 0) {
      mp[n] = f(n/2)+f(n/3);
    }
    return mp[n];
  }
}
void solve() {
  i64 n;
  cin >> n;

  cout << f(n) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
