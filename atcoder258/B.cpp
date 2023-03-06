#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string>a(n);
  for(int i =0;i<n;i++){
    cin >>a[i];
  }
  long long ans=0;
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
          if(di!=0|| dj!=0){
            long long num  =0;
            for(int  k=0;k<n;k++){
              int ni = ((i+di*k)%n+n)%n;
              int nj = ((j+dj*k)%n+n)%n;
              num  =num*10+(int)(a[ni][nj] -'0');
            }
            ans =max(ans, num);
          }
        }
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
