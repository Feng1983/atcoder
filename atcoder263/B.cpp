#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
  }
  int ans = 0;

  int x = n;
  while (p[x] != 1) {
    x = p[x];
    ans++;
  }
  cout <<ans +1<<endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
