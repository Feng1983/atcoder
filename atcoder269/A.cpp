#include<bits/stdc++.h>
using namespace std;


int main(){
  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n  ;
  cin >>n;

  int s1=0,t1=n;
  while( t1-s1>1){
    int mid =(s1+t1)/2;
    cout<<"? "<<1<<' '<<mid<<' '<<1<<' '<<n<<endl;
    int T;
    cin >> T;
    if(T==mid){
      s1=mid;
    }else{
      t1=mid;
    }
  }
  int s2=0,t2=n;
  while(t2-s2>1){
    int mid= (t2+s2)/2;
    cout<<"? "<<1 <<' '<<n <<' '<<1<<' '<<mid<<endl;
    int T;
    cin >> T;
    if(T==mid){
      s2=mid;
    }else{
      t2= mid;
    }
  }
  cout<<"! "<<s1+1<<' '<<s2+1<<endl;

  return 0;
}
