#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int lg =std:: __lg(n);
  std::vector ga(n, std::vector<int>(lg + 1)), gb(ga);
  for (int i = 0; i < n - 1; i++) {
    ga[i][0] = abs(a[i + 1] - a[i]);
    gb[i][0] = abs(b[i + 1] - b[i]);
  }
  for (int j = 0; j < lg; j++) {
    for (int i = 0; i + (2 << j) < n; i++) {
      ga[i][j + 1] = std::gcd(ga[i][j], ga[i + (1 << j)][j]);
      gb[i][j + 1] = std::gcd(gb[i][j], gb[i + (1 << j)][j]);
    }
  }

  auto query = [&](auto &g, int l, int r) {
    if (l == r) {
      return 0;
    }
    int k = __lg(r - l);
    return std::gcd(g[l][k], g[r - (1 << k)][k]);
  };

  for (int i = 0; i < q; i++) {
    int x1, x2, y1, y2;
    std::cin >> x1>> x2>> y1>> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    auto ans = gcd(a[x1] + b[y1], gcd(query(ga, x1, x2), query(gb, y1, y2)));
    cout << ans << "\n";
  }
  return 0;
}
