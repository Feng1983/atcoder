#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<array<int, 2>>> elev(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    elev[a].push_back({b, c});
  }
  vector<array<int, 2>> segs;
  for (int i = 0; i < n; i++) {
    sort(elev[i].begin(), elev[i].end());
    vector<array<int, 2>> temp;
    for (auto [l, r] : elev[i]) {
      if (!temp.empty() && l <= temp.back()[1]) {
        temp.back()[1] = std::max(temp.back()[1], r);
      } else {
        temp.push_back({l, r});
      }
    }
    elev[i] = temp;
    for (auto s : temp) {
      segs.push_back(s);
    }
  }
  std::sort(segs.begin(), segs.end());
  std::vector<std::array<int, 2>> temp;
  for (auto [l, r] : segs) {
    if (!temp.empty() && r <= temp.back()[1]) {
      continue;
    }
    if (!temp.empty() && l == temp.back()[0]) {
      temp.pop_back();
    }
    temp.push_back({l, r});
  }
  segs = temp;
  const int N = segs.size();
  const int lg = __lg(N);
  vector<vector<int>> jump(N, vector<int>(lg + 1));

  for (int i = 0, j = 0; i < N; i++) {
    while (j + 1 < N && segs[j + 1][0] <= segs[i][1]) {
      j++;
    }
    jump[i][0] = j;
  }
  for (int j = 0; j < lg; j++) {
    for (int i = 0; i < N; i++) {
      jump[i][j + 1] = jump[jump[i][j]][j];
    }
  }

  for (int i = 0; i < q; i++) {
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    x--;
    z--;
    if (y > w) {
      swap(x, z);
      swap(y, w);
    }

    int ans = w - y;
    auto it =
        lower_bound(elev[x].begin(), elev[x].end(), array<int, 2>{y + 1, -1});
    if (it != elev[x].begin()) {
      it--;
      if (y <= (*it)[1]) {
        y = (*it)[1];
      }
    }
    it = lower_bound(elev[z].begin(), elev[z].end(), array<int, 2>{w + 1, -1});
    if (it != elev[z].begin()) {
      it--;
      if (w <= (*it)[1]) {
        w = (*it)[0];
      }
    }
    if (y >= w) {
      ans += x != z;
    } else {
      it = lower_bound(segs.begin(), segs.end(), array<int, 2>{y + 1, -1});
      if (it == segs.begin()) {
        ans = -1;
      } else {
        it--;
        if (y > (*it)[1]) {
          ans = -1;
        } else {
          int j = it - segs.begin();
          if (segs[j][1] >= w) {
            ans += 2;
          } else {
            ans += 3;
            for (int k = lg; k >= 0; k--) {
              if (segs[jump[j][k]][1] < w) {
                j = jump[j][k];
                ans += 1 << k;
              }
            }
            j = jump[j][0];
            if (segs[j][1] < w) {
              ans = -1;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
