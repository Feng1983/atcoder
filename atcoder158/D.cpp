#include <bits/stdc++.h>
using namespace std;

#define ll  long long


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string  s;
    int q;
    cin>>s;
    cin>>q;
    bool st=0;
    vector<char> v[2];
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            //reverse(ans.begin(),ans.end());
            st=!st;
        }else if(t==2){
            int f;
            char c;

            cin>>f>>c;
            --f;
            v[f^st].push_back(c);
        }
    }
    string ans;
    for(int i=(int)v[0].size()-1;~i;--i)
        ans+=v[0][i];
    ans+=s;

    for(char c: v[1])
        ans+=c;
    if(st)
        reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
