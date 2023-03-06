#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000000;

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    long long D,K, X;
    cin >> D >> K >> X;
    long long ans =INF;
    vector<long long> S(D+1);

    S[0]=1;
    for(int j=0;j<D;j++){
      S[j+1]= S[j]*K+1;
    }
    for(int j =0;j<=D;j++){
      if(X<=S[j]){
        long long cnt=0;
        if(j<D){
          cnt++;
        }
        long long curr =S[j];
        for(int k=j-1;k>=0;k--){
          long long q=(curr-X)/S[k];
          cnt+=q;
          curr-= q*S[k];
        }
        ans= min(ans, cnt);
      }
    }
    cout<<ans<<endl;
  }
}
