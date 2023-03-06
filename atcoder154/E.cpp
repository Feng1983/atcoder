#include <bits/stdc++.h>
using namespace std;

#define ll  long long

string n;
int k,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    m = n.size();
    int ans=0;
    for(int i=0;i<m;i++){
        for(int d1=1;d1<=9;d1++){
            if(i==0 && d1>n[0]-'0')continue;

            bool less1= i||d1<n[0]-'0';
            if(k==1){
                ++ans;
            }else{
                for(int j=i+1;j<m;++j){
                    for(int d2=1;d2<=9;++d2){
                        if(!less1&& d2>n[j]-'0')
                            continue;
                        bool less2= less1|| d2<n[j]-'0';
                        if(k==2){
                            ++ans;
                        }else{
                            for(int k=j+1;k<m;++k){
                                for(int d3=1;d3<=9;++d3){
                                    if(!less2 && d3>n[k]-'0')
                                        continue;
                                    ++ans;
                                }
                                if(n[k]>'0')
                                    less2=1;
                            }
                        }
                    }
                    if(n[j]>'0')
                        less1=1;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
