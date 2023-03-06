#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> A(n);
  for (int i = 0; i < n; i++) {
    A[i].push_back(i);
  }
  int cnt = n;
  vector<int> pos1(n);
  for (int i = 0; i < n; i++) {
    pos1[i] = i;
  }
  vector<int> pos2(n), p2p(n);
  for (int i = 0; i < n; i++) {
    pos2[i] = i;
    p2p[i] = i;
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int X, Y;
      cin >> X >> Y;
      X--;
      Y--;
      if (A[X].size() < A[Y].size()) {
        int x = p2p[X];
        int y = p2p[Y];
        swap(pos2[x], pos2[y]);
        swap(p2p[X], p2p[Y]);
        swap(A[X], A[Y]);
      }
      for (int j : A[Y]) {
        pos1[j] = p2p[X];
        A[X].push_back(j);
      }
      A[Y].clear();
    }
    if (t == 2) {
      int X;
      cin >> X;
      X--;
      A[X].push_back(cnt);
      pos1.push_back(p2p[X]);
      cnt++;
    }
    if (t == 3) {
      int X;
      cin >> X;
      X--;
      cout << pos2[pos1[X]] + 1 << endl;
    }
  }

  return 0;
}
