#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> A(n, 0), B(n, 0);
  vector<long long> C(n, 0);

  for (int i = 0; i < n; i++) {
    int l = s[i].size();
    for (int j = 0; j < l; j++) {
      if (s[i][j] == 'X') {
        A[i]++;
      } else {
        B[i] += s[i][j] - '0';
        C[i] += A[i] * (s[i][j] - '0');
      }
    }
  }
  function<bool(int, int)> comp = [&](int i, int j) {
    return (long long)A[i] * B[j] > (long long)A[j] * B[i];
  };
  vector<int> P(n);
  for (int i = 0; i < n; i++) {
    P[i] = i;
  }
  sort(P.begin(), P.end(), comp);
  long long ans = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    ans += C[P[i]];
    ans += (long long)sum * B[P[i]];
    sum += A[P[i]];
  }
  cout << ans << endl;
  return 0;
}
