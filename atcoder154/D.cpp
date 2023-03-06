#include <bits/stdc++.h>
using namespace std;

#define ll  long long

int n,k,p[200001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p[i+1];
        p[i+1]+=p[i];
    }
       
    int ans=0;
    for(int i=k;i<=n;++i){
        ans= max(ans, p[i]-p[i-k]);
    }
    cout<<double(ans+k)/2.0<<endl;
    return 0;
}
