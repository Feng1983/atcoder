#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  multiset<int> s;
  long long a = 0;
  int x;
  while (n--) {
    cin >> x;
    s.insert(x);
    s.insert(x);
    a += x - *s.begin();
    s.erase(s.begin());
  }
  cout << a;
}

bool doit(int i) {
  vector<int> f;
  f.push_back(12);
  int r = 10;
  vector<int> f2;

  f2.push_back(223);
  return 1;
}
