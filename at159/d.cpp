#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin>>n;
    vector<long long> r(n);
    vector<long long> a(n+1);

    for(int i=0;i<n;i++){
        cin>>r[i];
        a[r[i]]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<2)continue;
        else{
            ans+= ((a[i]-1))*(a[i])/2;
        }
    }
    for(int i=0;i<n;i++){
       
        if(a[r[i]]<2){
            cout<<ans<<endl;
        }
        else if(a[r[i]]==2){
            cout<<ans-1<<endl;
            //cout<<t<<endl;
        }else{
            long long anss= ans- (a[r[i]]-1)*a[r[i]]/2+(a[r[i]]-1)*(a[r[i]]-2)/2;
            cout<<anss<<endl;
        }
        
    }


    return 0;
}
