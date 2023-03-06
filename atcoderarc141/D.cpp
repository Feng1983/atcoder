#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin  >> n >> m;
  vector<bool> has(2*m+1);
  for(int i = 0;i<n;i++){
    int x;
    cin >> x;
    has[x]=true;
  }
  vector<vector<bool>> b(2*m);
  for(int i=1;i<2*m;i+=2){
    for(int j =i;j<=2*m; j*=2){
      b[i].push_back(has[j]);
    }
  }
  vector<int> L(2*m,-1);
  vector<int> R(2*m,-1);
  for(int i=1;i<2*m;i+=2){
    L[i] = 0;
    R[i] = (int)b[i].size()-1;
  }
  for(int i  =1;i<2*m;i+=2){
    while(R[i] >=0&& !b[i][R[i]]){
      R[i]-=1;
    }
    for(int j=3*i; j<2*m;j+=2*i){
      R[j] = min(R[j], R[i]-1);
    }
  }
  for(int i=2*m-1; i>=1;i-=2){
    for(int j=3*i; j<2*m;j+=2*i){
      L[i] = max(L[i], L[j]+1);  
    }
    while(L[i] <(int)b[i].size()&& !b[i][L[i]]){
      L[i]+=1;
    }
  }
  for(int i=1;i<2*m;i+=2){
    if(L[i] > R[i]){
      for(int j=0;j<n;j++){
        cout<<"No"<<endl;
      }
      return 0;
    }
  }
  for(int i=1;i<=2*m;i++){
    if(has[i]){
      int x=i;
      int k = 0;
      while(x%2==0){
        x/=2;
        k+=1;
      }
      cout<< (k>=L[x] && k<=R[x] ?"Yes": "No")<<endl;
    }
    
  }
  

  return 0;
}
