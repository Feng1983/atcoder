#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const long long MOD = 998244353;

int main() {
  vector<long long> inv(MAX);
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<long long> fact(MAX * 2 - 2);
  fact[0] = 1;
  for (int i = 1; i < MAX * 2 - 2; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  vector<long long> finv(MAX);
  finv[0] = 1;
  for (int i = 1; i < MAX; i++) {
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    long long A =
        (N + 1) * fact[N * 2 - 3] % MOD * finv[N - 1] % MOD * finv[N - 2] % MOD;
    long long B =
        N * fact[N * 2 - 4] % MOD * finv[N - 2] % MOD * finv[N - 2] % MOD;
    cout << (A - B + MOD) % MOD << endl;
  }
}
