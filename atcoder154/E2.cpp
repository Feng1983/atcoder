#include <bits/stdc++.h>
using namespace std;

#define ll  long long

//string n;
//int k,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll ans=0;
    string s;
    ll k;
    cin>>s>>k;

    ll n= s.size();

    vector<vector<ll>>dp0(n+1,vector<ll>(k+1)),dp1(n+1,vector<ll>(k+1));

    ll  m=s[0]-'0';
    dp0[0][0]=1;
    dp0[0][1]=m-1;
    dp1[0][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<k+1;j++){
            if(s[i]=='0'){
                dp0[i][j] =dp0[i-1][j];
                dp1[i][j]=dp1[i-1][j];
                if(j)dp0[i][j]+=9*dp0[i-1][j-1];
            }else{
                m=s[i]-'0';
                dp0[i][j]= dp0[i-1][j];//0
                dp0[i][j] +=dp1[i-1][j];//0
                if(j){
                    dp0[i][j] +=9*dp0[i-1][j-1];//non zero
                    dp0[i][j] +=(m-1)*dp1[i-1][j-1];//non zero
                    dp1[i][j] =dp1[i-1][j-1];//eq
                }
            }
        }
    }
    ans = dp0[n-1][k]+dp1[n-1][k];
    cout<<ans<<endl;
    return 0;
}
