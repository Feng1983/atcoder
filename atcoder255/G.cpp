#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<long long> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<long long> X(m), Y(m);
  for (int i = 0; i < m; i++) {
    cin >> X[i] >> Y[i];
    Y[i] = X[i] - Y[i];
  }
  map<long long, vector<long long>> mp;
  for (int i = 0; i < m; i++) {
    mp[X[i]].push_back(Y[i]);
  }
  map<long long, long long> cnt;
  vector<pair<long long, long long>> G;

  for (auto P : mp) {
    map<long long, long long> cnt2;
    for (long long x : P.second) {
      auto itr = lower_bound(G.begin(), G.end(), make_pair(x, (long long)-1));
      long long g;
      if (itr == G.end()) {
        g = x - G.size();
      } else if ((*itr).first != x) {
        g = x - (itr - G.begin());
      } else {
        g = (*itr).second;
      }
      cnt2[g]++;
    }
    long long g2 = -1;
    for (auto P : cnt2) {
      if (cnt.count(P.first) == 1) {
        if (cnt[P.first] == P.second - 1) {
          g2 = P.first;
          break;
        }
      } else if (P.second == 1) {
        g2 = P.first;
        break;
      }
    }
    if (g2 != -1) {
      G.push_back(make_pair(P.first, g2));
      cnt[g2]++;
    }
  }

  long long x = 0;
  for (int i = 0; i < n; i++) {
    auto itr = lower_bound(G.begin(), G.end(), make_pair(A[i], (long long)-1));
    long long g;
    if (itr == G.end()) {
      g = A[i] - G.size();
    } else if ((*itr).first != A[i]) {
      g = A[i] - (itr - G.begin());
    } else {
      g = (*itr).second;
    }
    x ^= g;
  }
  if (x > 0) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
