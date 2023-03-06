#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;
template <typename T> struct segment_tree {
  int N;
  vector<T> ST;
  function<T(T, T)> f;
  T E;
  segment_tree(int n, function<T(T, T)> f, T E) : f(f), E(E) {
    N = 1;
    while (N < n) {
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
  }
  T operator[](int k) { return ST[N - 1 + k]; }
  void update(int k, T x) {
    k += N - 1;
    ST[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);
    }
  }
  T query(int L, int R, int i, int l, int r) {
    if (r <= L || R <= l) {
      return E;
    } else if (L <= l && r <= R) {
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
    }
  }
  T query(int L, int R) { return query(L, R, 0, 0, N); }
};
int main() {
  int n;
  cin >> n;
  vector<int> P(n);
  for (int i = 0; i < n; i++) {
    cin >> P[i];
    P[i]--;
  }
  function<int(int, int)> mn = [](int a, int b) { return min(a, b); };
  vector<int> ans(n, INF);
  segment_tree<int> ST1(n, mn, INF), ST2(n, mn, INF);
  for (int i = 0; i < n; i++) {
    ans[i] = min(ans[i], (i + P[i]) + ST1.query(0, P[i]));
    ans[i] = min(ans[i], (i - P[i]) + ST2.query(P[i] + 1, n));
    ST1.update(P[i], -i - P[i]);
    ST2.update(P[i], -i + P[i]);
  }
  segment_tree<int> ST3(n, mn, INF), ST4(n, mn, INF);
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = min(ans[i], (-i + P[i]) + ST3.query(0, P[i]));
    ans[i] = min(ans[i], (-i - P[i]) + ST4.query(P[i] + 1, n));
    ST3.update(P[i], i - P[i]);
    ST4.update(P[i], i + P[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i < n - 1) {
      cout << ' ';
    }
  }
  cout << endl;
}
