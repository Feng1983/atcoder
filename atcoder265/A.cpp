#include<bits/stdc++.h>
using namespace std;

void solve(){
  int x, y, n;
  cin >> x>> y>>n;

  if(x*3<=y){
    cout<<x*n<<endl;
  }else if(n<3){

    cout<<x*n<<endl;
  }else{
    int t =n/3;
    cout<<(n-t*3)*x+t*y<<endl;
  }
}

int main(){
  solve();

  return 0;

}
