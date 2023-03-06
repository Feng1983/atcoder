#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long sum(long long x) { return x * (x + 1) / 2; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, a, b;
  cin >> n >> a >> b;
  long long ans = (n + 1) * 1LL * (n) / 2;
  ans -= sum(n / a) * a;
  ans -= sum(n / b) * b;
  long long cm = lcm(a, b);
  if (cm <= n) {
    ans+=sum(n/cm)*cm;
  }
  cout<< ans<<endl;

  return 0;
}
