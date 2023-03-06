#include <bits/stdc++.h>
using namespace std;

#define ll  long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    int ans=0;
    while(n){
        n/=k;
        ans++;
    }

    cout<<ans<<endl;
    return 0;
}
