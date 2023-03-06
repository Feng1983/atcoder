#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    int lg = std::__lg(n);
    std::vector ga(n, std::vector<int>(lg + 1)), gb(ga);
    for (int i = 0; i < n - 1; i++) {
        ga[i][0] = std::abs(a[i + 1] - a[i]);
        gb[i][0] = std::abs(b[i + 1] - b[i]);
    }
    
    for (int j = 0; j < lg; j++) {
        for (int i = 0; i + (2 << j) < n; i++) {
            ga[i][j + 1] = std::gcd(ga[i][j], ga[i + (1 << j)][j]);
            gb[i][j + 1] = std::gcd(gb[i][j], gb[i + (1 << j)][j]);
        }
    }
    
    auto query = [&](auto &g, int l, int r) {
        if (l == r) {
            return 0;
        }
        int k = std::__lg(r - l);
        return std::gcd(g[l][k], g[r - (1 << k)][k]);
    };
    
    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> x2 >> y1 >> y2;
        
        x1--;
        y1--;
        x2--;
        y2--;
        
        auto ans = std::gcd(a[x1] + b[y1], std::gcd(query(ga, x1, x2), query(gb, y1, y2)));
        std::cout << ans << "\n";
    }
    
    return 0;
}
