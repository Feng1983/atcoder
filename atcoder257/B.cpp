#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k,q ;
  cin >> n >> k >>q;

  vector<int>a(k+1);
  a[k] = n;
  for(int i  = 0; i<k;i++){
    cin >> a[i];
    --a[i];
  }
  for(int i  =0; i <q ;i++){
    int j ; 
    cin >>j;
    --j;
    if(a[j]+1 <a[j+1]){
      a[j]++;
    }
  }
  for(int i = 0 ;i<k;i++){
    cout<<a[i]+1 <<" \n"[i==k-1];
  }

  return 0;

}
