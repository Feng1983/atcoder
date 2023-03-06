#include<bits/stdc++.h>
using namespace std;
constexpr int P = 998244353;
using i64 = long long;

// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

int main(){
  int R, G, B ,K;
  cin >> R >> G >> B >> K;
  const int N = R+G+B;

  vector<Z>fac(N+1), invfac(N+1);
  fac[0]=1;
  for(int i = 1;i<=N;i++){
    fac[i] =fac[i-1]*i;
  }
  invfac[N] = fac[N].inv();
  for(int  i =N;i;i--){
    invfac[i-1] =invfac[i]*i;
  }
  //C(R+B, R)*C(R, K)*C(G+B, G-k)
  Z ans = fac[R+B]*invfac[R]*invfac[B]*fac[R]*invfac[K]*invfac[R-K]*fac[G+B]*invfac[K+B]*invfac[G-K];
  cout<< ans<<endl;
  return 0;
}
