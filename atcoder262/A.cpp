#include<bits/stdc++.h>
using namespace std;


 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int y ;
   cin >>y;
   for(int i =0;i<10;i++){
     if((i+y)%4==2){
       cout<<(i+y)<<endl;
       break;
     }
   }

  return 0;
}

