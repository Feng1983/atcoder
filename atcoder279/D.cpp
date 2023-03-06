#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
void solve() {
  cout << fixed << setprecision(20);
  double A, B;
  cin >> A >> B;
  double ans = A;
  long long L = 0, R = 1000000000000000;
  while (R - L >= 3) {
    long long m1 = (L * 2 + R) / 3;
    long long m2 = (L + R * 2) / 3;
    double x1 = B * m1 + A / sqrt(m1 + 1);
    double x2 = B * m2 + A / sqrt(m2 + 1);
    ans = min(ans, x1);
    ans = min(ans, x2);
    if (x1 > x2) {
      L = m1;
    } else {
      R = m2;
    }
  }
  int c = (L + R) / 2;
  double x = B * c + A / sqrt(c + 1);
  ans = min(ans, x);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
