#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n ;
  long long P,Q, R;
  cin >> n >> P >>Q >>R;
  vector<int> A(n);
  for(int i = 0;i<n;i++){
    cin >> A[i];
  }
  vector<long long>S(n+1);
  S[0]= 0;
  for(int i =0;i<n;i++){
    S[i+1] =S[i] +A[i];
  }
  set<long long> st;
  for(int  i=0 ; i<=n;i++){
    st.insert(S[i]);
  }
  bool ok=false;
  for(int i = 0;i<=n;i++){
    if(st.count(S[i]+P ) ==1 && st.count(S[i]+P+Q)==1&& st.count(S[i]+P+Q+R)){
      ok=true;
    }
  }
  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}

int main(){
  solve();

  return 0;

}
