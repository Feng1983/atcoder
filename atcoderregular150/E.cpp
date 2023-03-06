#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int bal = 0;
  for (char c : s) {
    if (c == 'L') {
      bal += 1;
    } else {
      bal -= 1;
    }
  }
  if (bal < 0) {
    reverse(s.begin(), s.end());
    for (char &c : s) {
      c ^= ('L' ^ 'R');
    }
    bal = -bal;
  }
  vector<int> till(n);
  mint ans = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int nxt = cur + (s[i] == 'R' ? -1 : 1);
    int bound = (s[i] == 'L' ? 0 : bal);
    int me = max(nxt, cur);
    if (me <= bound) {
      //me+till[i]*bal<=bound
      int low = 0, high = k - 1;
      while (low < high) {
        int mid = (low + high + 1) >> 1;
        if (me + (long long)mid * bal <= bound) {
          low = mid;
        } else {
          high = mid - 1;
        }
      }
      till[i] = low;
    } else {
      till[i] = -1;
    }
    ans += till[i] + 1;
    cur = nxt;
  }
  if (bal > 0) {
    string last = "";
    for (int i = 0; i < n; i++) {
      if (till[i] == k - 1) {
        last += s[i] ^ 'L' ^ 'R';
      } else {
        last += s[i];
      }
    }
    int cnt = 0;
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      cur += (last[i] == 'R' ? 1 : -1);
      if (cur < 0) {
        break;
      }
      if (cur == 0) {
        cnt = n - i;
      }
    }
    ans -= cnt / 2;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        ans += till[i] + 1;
      } else {
        ans += k - 1 - till[i];
      }
    }
  }
  cout << ans.val() << endl;
  return 0;
}
