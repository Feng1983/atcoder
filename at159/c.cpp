#include<bits/stdc++.h>
using namespace std;

bool isok(string  t){
    int n =t.size();
    for(int i=0;i<n/2;i++){
        if(t[i]!=t[n-1-i])
            return false;
    }
    return true;
}
int main(){
    
    int L;
    cin>>L;

    double v= L*1.0/3;
    
    cout<<v*v*v<<endl;
    return 0;
}
