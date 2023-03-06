#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long L, R;
  cin >> N >> L >> R;
  L--;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<long long> B;
  for (int i = 0; i < N; i++) {
    for (long long x : B) {
      A[i] = min(A[i], A[i] ^ x);
    }
    if (A[i] > 0) {
      B.push_back(A[i]);
    }
  }
  int cnt = B.size();
  for (int i = 0; i < cnt; i++) {
    int p = i;
    for (int j = i + 1; j < cnt; j++) {
      if (B[j] > B[p]) {
        p = j;
      }
    }
    swap(B[i], B[p]);
    for (int j = 0; j < cnt; j++) {
      if (j != i) {
        B[j] = min(B[j], B[j] ^ B[i]);
      }
    }
  }
  for (long long i = L; i < R; i++) {
    long long ans = 0;
    for (int j = 0; j < cnt; j++) {
      if ((i >> (cnt - 1 - j) & 1) == 0) {
        ans = min(ans, ans ^ B[j]);
      } else {
        ans = max(ans, ans ^ B[j]);
      }
    }
    cout << ans;
    if (i < R - 1) {
      cout << ' ';
    }
  }
  cout << endl;
}
