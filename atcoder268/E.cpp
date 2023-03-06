#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int>p(n);
  for(int i = 0;i<n;i++){
    cin >> p[i];
  }

  vector<long long> iv(n*2),ix(n*2);
  for(int i =0;i<n;i++){
    int j  =(p[i]-i+n)%n;
    iv[j]-=j;
    iv[j+n/2+1]+=j;
    ix[j]+=1;
    ix[j+n/2+1]-=1;
    iv[n+j-(n-1)/2] += n+j;
    iv[n+j] -= n+j;
    ix[n+j-(n-1)/2]-=1;
    ix[n+j]+=1;
  }
  for(int i = 0;i<2*n-1;i++){
    iv[i+1]+=iv[i];
    ix[i+1]+=ix[i];
  }
  	long long ans = 1000000000000000000;
    for(int i = 0;i<n;i++){
      ans =min(ans, iv[i] +ix[i]*i+iv[i+n]+ix[i+n]*(i+n));

    }
    cout<<ans<<endl;
}
// n+j-n/2+1/2=n/2+j+1/2;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t=1;
  while(t--){
    solve();
  }

  return 0;
}
