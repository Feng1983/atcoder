#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, D, K;
    cin >> N >> D >> K;
    K--;
    int L = N / gcd(N, D);
    cout<<(long long)D*(K%L)%N+K/L <<endl;
  }

  return 0;
}
