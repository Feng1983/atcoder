#include <bits/stdc++.h>
using namespace std;
template <typename T, typename F> struct lazy_segment_tree {
  int N;
  vector<T> ST;
  vector<F> lazy;

  function<T(T, T)> op;
  function<T(F, T)> mp;
  function<F(F, F)> comp;

  T E;
  F id;
  lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(F, T)> mp,
                    function<F(F, F)> comp, T E, F id)
      : op(op), mp(mp), comp(comp), E(E), id(id) {

    int n = A.size();
    N = 1;
    while (N < n) {
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
    for (int i = 0; i < n; i++) {
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--) {
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
    lazy = vector<F>(N * 2 - 1, id);
  }
  void push(int i) {
    if (i < N - 1) {
      lazy[i * 2 + 1] = comp(lazy[2 * i + 1], lazy[i]);
      lazy[i * 2 + 2] = comp(lazy[i * 2 + 2], lazy[i]);
    }
    ST[i] = mp(lazy[i], ST[i]);
    lazy[i] = id;
  }
  void range_apply(int L, int R, F f, int i, int l, int r) {
    push(i);
    if (r <= L || R <= l) {
      return;
    } else if (L <= l && r <= R) {
      lazy[i] = f;
      push(i);
    } else {
      int m = (l + r) / 2;
      range_apply(L, R, f, i * 2 + 1, l, m);
      range_apply(L, R, f, i * 2 + 2, m, r);
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void range_apply(int L, int R, F f) { range_apply(L, R, f, 0, 0, N); }
  T range_fold(int L, int R, int i, int l, int r) {
    push(i);
    if (r <= L && R <= l) {
      return E;
    } else if (L <= l && r <= R) {
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return op(range_fold(L, R, i * 2 + 1, l, m),
                range_fold(L, R, i * 2 + 2, m, r));
    }
  }

  T range_fold(int L, int R) { return range_fold(L, R, 0, 0, N); }
};

struct monoid {
  array<int, 3> cnt;
  long long cnt10, cnt20, cnt21;
  monoid() : cnt({0, 0, 0}), cnt10(0), cnt20(0), cnt21(0) {}
};

struct s {
  array<int, 3> p;
  s() : p({-1, -1, -1}) {}
  s(int S, int T, int U) : p({S, T, U}) {}
};
long long get(monoid &A, int x, int y) {
  if (x == 1 && y == 0) {
    return A.cnt10;
  }
  if (x == 2 && y == 0) {
    return A.cnt20;
  }
  if (x == 2 && y == 1) {
    return A.cnt21;
  }
  if (x == 0 && y == 1) {
    return (long long)A.cnt[0] * A.cnt[1] - A.cnt10;
  }
  if (x == 0 && y == 2) {
    return (long long)A.cnt[0] * A.cnt[2] - A.cnt20;
  }
  if (x == 1 && y == 2) {
    return (long long)A.cnt[1] * A.cnt[2] - A.cnt21;
  }
  return -1;
}

int main() {

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<monoid> A2(N);
  for (int i = 0; i < N; i++) {
    A2[i].cnt[A[i]]++;
  }
  function<monoid(monoid, monoid)> op = [](monoid A, monoid B) {
    monoid ans;
    for (int i = 0; i < 3; i++) {
      ans.cnt[i] = A.cnt[i] + B.cnt[i];
    }
    ans.cnt10 = A.cnt10 + B.cnt10 + (long long)A.cnt[1] * B.cnt[0];
    ans.cnt20 = A.cnt20 + B.cnt20 + (long long)A.cnt[2] * B.cnt[0];
    ans.cnt21 = A.cnt21 + B.cnt21 + (long long)A.cnt[2] * B.cnt[1];
    return ans;
  };

  function<monoid(s, monoid)> mp = [](s p, monoid A) {
    if (p.p[0] == -1) {
      return A;
    }
    monoid ans;
    for (int i = 0; i < 3; i++) {
      ans.cnt[p.p[i]] += A.cnt[i];
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (p.p[i] == 1 && p.p[j] == 0) {
          ans.cnt10 += get(A, i, j);
        }
        if (p.p[i] == 2 && p.p[j] == 0) {
          ans.cnt20 += get(A, i, j);
        }
        if (p.p[i] == 2 && p.p[j] == 1) {
          ans.cnt21 += get(A, i, j);
        }
      }
    }
    return ans;
  };
  function<s(s, s)> comp = [](s a, s b) {
    if (a.p[0] == -1) {
      return b;
    }
    if (b.p[0] == -1) {
      return a;
    }
    s ans;
    for (int i = 0; i < 3; i++) {
      ans.p[i] = b.p[a.p[i]];
    }
    return ans;
  };
  lazy_segment_tree<monoid, s> ST(A2, op, mp, comp, monoid(), s());
  for(int i = 0;i<Q;i++){
    int t;
    cin >> t;
    if(t==1){
      int L, R;
      cin >> L >> R;
      L--;
      monoid  res = ST.range_fold(L, R);
      cout<<res.cnt10+res.cnt20+res.cnt21<<endl;
    }
    if(t==2){
      int L, R, S, T, U;
      cin >> L >> R >>S >> T>>U;
      L--;
      ST.range_apply(L, R, s{S, T, U});
    }
      
  }

  return 0;
}
