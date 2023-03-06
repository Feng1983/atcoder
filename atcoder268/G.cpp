#include <bits/stdc++.h>
using namespace std;

const long long HALF = 499122177;
const long long MOD = 998244353;

void dfs(vector<long long> &ans, vector<pair<string, int>> &P, long long x,
         int L, int R, int d) {
  if (R - L == 1) {
    ans[P[L].second] = x;
    return;
  }
  vector<int> id;
  vector<char> ch;
  id.push_back(L);
  ch.push_back(P[L].first[d]);
  for (int i = L + 1; i < R; i++) {
    if (P[i].first[d] != P[i - 1].first[d]) {
      id.push_back(i);
      ch.push_back(P[i].first[d]);
    }
  }
  id.push_back(R);
  int cnt = id.size() - 1;
  int p = 0;
  if (ch[0] == '$') {
    dfs(ans, P, x, L, id[1], d + 1);
    p = 1;
    x++;
    x %= MOD;
  }
  int s = R - L - p;
  for (int i = p; i < cnt; i++) {
    long long x2 = (x + (s - (id[i + 1] - id[i])) * HALF) % MOD;
    dfs(ans, P, x2, id[i], id[i + 1], d + 1);
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    s[i] += '$';
  }
  vector<pair<string, int>> P(n);
  for (int i = 0; i < n; i++) {
    P[i] = make_pair(s[i], i);
  }
  sort(P.begin(), P.end());
  vector<long long> ans(n, 0);
  dfs(ans, P, 1, 0, n, 0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
