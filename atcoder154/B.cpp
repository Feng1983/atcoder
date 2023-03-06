#include <bits/stdc++.h>
using namespace std;

#define ll  long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int sz=s.size();
    string ans="";
    for(int i=0;i<sz;i++)
        ans+='x';
    cout<<ans<<endl;
}
