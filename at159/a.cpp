#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int ans=0;

    if(n>=2){
        ans+=  (n-1)*n/2;
    }

    if(m>=2){
        ans+= (m-1)*m/2;
    }

    cout<<ans<<endl;
    return 0;
}
