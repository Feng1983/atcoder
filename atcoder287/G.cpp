#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
template <typename T> struct binary_indexed_tree {
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {}
  void add(int i, T x) {
    i++;
    while (i <= N) {
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i) {
    T ans = 0;
    while (i > 0) {
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    a[i] *= -1;
  }
  int Q;
  cin >> Q;
  vector<int> t(Q), x(Q), y(Q);
  for (int i = 0; i < Q; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> x[i] >> y[i];
      x[i]--;
      y[i] *= -1;
    }
    if (t[i] == 2) {
      cin >> x[i] >> y[i];
      x[i]--;
    }
    if (t[i] == 3) {
      cin >> x[i];
    }
  }
  vector<int> a2 = a;
  for (int i = 0; i < Q; i++) {
    if (t[i] == 1) {
      a2.push_back(y[i]);
    }
  }
  sort(a2.begin(), a2.end());
  a2.erase(unique(a2.begin(), a2.end()), a2.end());
  for (int i = 0; i < N; i++) {
    a[i] = lower_bound(a2.begin(), a2.end(), a[i]) - a2.begin();
  }
  for (int i = 0; i < Q; i++) {
    if (t[i] == 1) {
      y[i] = lower_bound(a2.begin(), a2.end(), y[i]) - a2.begin();
    }
  }
  int M = a2.size();
  binary_indexed_tree<long long> BIT1(M), BIT2(M);
  for (int i = 0; i < N; i++) {
    BIT1.add(a[i], b[i]);
    BIT2.add(a[i], (long long)a2[a[i]] * b[i]);
  }
  for (int i = 0; i < Q; i++) {
    if (t[i] == 1) {
      BIT1.add(a[x[i]], -b[x[i]]);
      BIT2.add(a[x[i]], (long long)-a2[a[x[i]]] * b[x[i]]);
      a[x[i]] = y[i];
      BIT1.add(a[x[i]], b[x[i]]);
      BIT2.add(a[x[i]], (long long)a2[a[x[i]]] * b[x[i]]);
    }
    if (t[i] == 2) {
      BIT1.add(a[x[i]], -b[x[i]]);
      BIT2.add(a[x[i]], (long long)-a2[a[x[i]]] * b[x[i]]);
      b[x[i]] = y[i];
      BIT1.add(a[x[i]], b[x[i]]);
      BIT2.add(a[x[i]], (long long)a2[a[x[i]]] * b[x[i]]);
    }
    if (t[i] == 3) {
      if (BIT1.sum(M) < x[i]) {
        cout << -1 << endl;
      } else {
        int tv = 0, fv = M + 1;
        int s = 0;
        while (fv - tv > 1) {
          int mid = (tv + fv) / 2;
          int t = BIT1.sum(mid);
          if(t<=x[i]){
            s=t;
            tv= mid;
          }else{
            fv=mid;
          }
        }
        cout<<-(BIT2.sum(tv)+(long long)a2[tv]*(x[i]-s))<<endl;
      }
    }
  }
}
