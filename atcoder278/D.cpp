#include<bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int>A(n);
  for(int i =0;i<n;i++){
    cin >> A[i];
  }
  int X=0;
  vector<long long> B(n);
  for(int i =0;i<n;i++){
    B[i] =A[i];
  }
  stack<int>st;
  for(int i=0;i<n;i++){
    st.push(i);
  }
  int Q;
  cin >> Q;
  for(int i =0;i<Q;i++){
    int T;
    cin >> T;
    if(T==1){
      int x;
      cin >> x;
      while(!st.empty()){
        B[st.top()]=0;
        st.pop();
      }
      X=x;
    }
    if(T==2){
      int p, x;
      cin >> p >> x;
      p--;
      st.push(p);
      B[p]+=x;
    }
    if(T==3){
      int p;
      cin >> p;
      p--;
      cout<<X+B[p]<<endl;
    }
  }

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
