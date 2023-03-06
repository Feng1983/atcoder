#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  long long X, A;
  int D;
  long long  N;
  cin >> X >> A>> D >>N;
  if(D< 0){
    A= A+(N-1)*D;
    D=-D;
  }
  if( X< A){
    cout<< A- X <<endl;

  }
  else if( X > A+(N-1)*D){
    cout<< X-(A+(N-1)*D)<<endl;
  }else if(D==0){
    cout<<abs(X-A)<<endl;
  }else{
    long long r  =(X-A)%D;
    cout<< min(r, D-r)<<endl;
  }

  return 0;

}
