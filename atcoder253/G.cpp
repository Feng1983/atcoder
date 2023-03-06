#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long l, r;
  int n;
  cin >> n >> l >> r;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  auto Process = [&](int from, int to) {
    int cnt = to - from + 1;
    reverse(a.end() - cnt, a.end());
    rotate(a.begin() + from, a.end() - cnt, a.end());
  };
  int x = -1;
  int y = -1;
  long long cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    long long from = max(l, cnt);
    long long to = min(r, cnt + (n - i - 2));
    if (from <= to) {
      from = from - cnt + (i + 1);
      to = to - cnt + (i + 1);
      if (from == i + 1 && to == n - 1) {
        if (x == -1) {
          x = y = i;
        } else {
          y += 1;
        }
      } else {
        if (x != -1) {
          Process(x, y);
          x = y = -1;
        }
        for (int j = from; j <= to; j++) {
          swap(a[i], a[j]);
        }
      }
    }
    cnt += n - i - 1;
  }
  if (x != -1) {
    Process(x, y);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }

  return 0;
}
