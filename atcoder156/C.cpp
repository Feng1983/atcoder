#include <bits/stdc++.h>
using namespace std;

#define ll  long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;vector<int> arr;
    cin>>n;
    int tot=0;
    for(int i=0;i<n;i++){
        int t=0;
        cin>>t;
        arr.push_back(t);
        tot+=t;
    }
    int p =tot/n;
    int ans1 =0,ans2=0;
    for(int i=0;i<n;i++){
        ans1+=(arr[i]-p)*(arr[i]-p);
        ans2+=(arr[i]-p-1)*(arr[i]-p-1);

    }
    
    
    cout<<min(ans1,ans2)<<endl;
    
    return 0;
}
