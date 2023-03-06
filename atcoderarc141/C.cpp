#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  n *= 2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    --b[i];
  }
  string s(n, ' ');
  int x = 0;
  int y = n - 1;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      while (s[a[x]] != ' ') {
        x += 1;
      }
      s[a[x]] = '(';
    } else {
      while (s[b[y]] != ' ') {
        y -= 1;
      }
      s[b[y]] = ')';
    }
  }
  vector<int> open;
  vector<int> close;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      open.push_back(i);
    } else {
      close.push_back(i);
    }
  }
  {
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
      int val;
      if (x == y || (x < n / 2 && open[x] < close[y])) {
        val = open[x++];
      } else {
        val = close[y++];
      }
      if (val != a[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  {
    int x = n / 2 - 1;
    int y = n / 2 - 1;
    for (int i = 0; i < n; i++) {
      int val;
      if (x == y || (x >= 0 && open[x] > close[y])) {
        val = open[x--];
      } else {
        val = close[y--];
      }
      if (val != b[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout <<  s << endl;
  return 0;
}
