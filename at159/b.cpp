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
    string s;
	cin>>s;
    if (s.size()%2==0){
        cout<<"No"<<endl;
    }else{
        int n= s.size();
        string par1= s.substr(0,(n-1)/2);
        string par2= s.substr((n+1)/2);

        if(isok(par1) && par1==par2){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
