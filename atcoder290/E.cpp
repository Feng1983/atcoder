#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int>A(N);

  for(int i =0;i<N;i++){
    cin >>A[i];
    A[i]--;
  }
  long long ans= 0;
  for(int i=2;i<=N;i++){
    ans+=(long long)(i/2)*(N-i+1);
  }
  vector<vector<int>> p(N);
  for(int i=0;i<N;i++){
    p[A[i]].push_back(i);
  }
  for(int i=0;i<N;i++){
    if(!p[i].empty()){
      int cnt = p[i].size();
      vector<long long>S(cnt+1);
      S[0] =0;
      for(int j=0;j<cnt;j++){
        S[j+1]=S[j]+N-p[i][j];
      }
      for(int j =0;j<cnt;j++){
        int c =upper_bound(p[i].begin()+j+1,p[i].end(),N-1-p[i][j])-p[i].begin();
        ans-= (long long)(c-j-1)*(p[i][j]+1);
        ans-= S[cnt]-S[c];
      }
    }
  }
    cout<<ans<<endl;

  return 0;
}
