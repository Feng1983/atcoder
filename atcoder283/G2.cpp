#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
const int K = 60;
struct bitbase {
  vector<ll> d;
  bitbase() : d(K) {}
  void add(ll x) {
    x = tomin(x);
    if (x == 0)
      return;
    for (int i = K - 1; i >= 0; i--) {
      if (x >> i & 1) {
        rep(j, K) if (d[j] >> i & 1) { d[j] ^= x; }
        d[i] = x;
        return;
      }
    }
  }
  ll tomin(ll x) {
    for (int i = K - 1; i >= 0; i--) {
      if (x >> i & 1)
        x ^= d[i];
    }
    return x;
  }
  ll get(ll x) {
    ll res = 0;
    rep(i, K) if (d[i]) {
      if (x & 1) {
        res ^= d[i];
      }
      x >>= 1;
    }
    return res;
  }
};

int main() {
  int n;
  ll r, l;
  cin >> n >> l >> r;
  bitbase b;
  rep(i, n) {
    ll a;
    cin >> a;
    b.add(a);
  }
  for (ll i = l; i <= r; i++) {
    cout << b.get(i - 1);
    if (i != r) {
      cout << ' ';
    }
  }
  cout<<endl;
}
