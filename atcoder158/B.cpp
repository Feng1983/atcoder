#include <bits/stdc++.h>
using namespace std;

#define ll  long long


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;

    int t= n/(a+b);
    int ans=0;

    ans+= t*a;
    if(n-t*(a+b)>=a)ans+=a;
    else{
        ans+=(n-t*(a+b));
    }
    cout<<ans<<endl;
    return 0;
}
