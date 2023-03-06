#include <bits/stdc++.h>
using namespace std;

#define ll  long long


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b;
    cin>>a>>b;

    for(int i=1;i<=1250;i++){
        int x= i*8/100,y=i*10/100;
        if(x<1&& y<1)continue;
        if(x==a &&y==b){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
