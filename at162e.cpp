#include <bits/stdc++.h>

typedef long long int64;

const int MOD=1e9+7;

int64 power_mod(int64 a, int64 n, int64 p=MOD){
    int64 ret=1;
    for(;n;n>>=1){
        if(n&1) ret=ret*a%p;
        a=a*a%p;
    }
    return ret;
}

void add(int& x, int y){
    x+=y;
    if(x>=MOD)x-=MOD;
}

using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int ret=0;
    vector<int> cnt(m+1);
    for(int i=m;i>=1;--i){
        cnt[i]=power_mod(m/i,n);
        for(int j=i+i;j<=m;j+=i)
        {
            add(cnt[i],MOD-cnt[j]);
        }

        add(ret, 1LL*i*cnt[i]%MOD);
    }
    printf("%d\n",ret);
    return 0;
}

