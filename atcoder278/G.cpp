#include <algorithm>
#include <bits/stdc++.h>
const int INF = 100000000;
using namespace std;
struct mex_set {
  set<pair<int, int>> st;
  mex_set() {
    st.insert(make_pair(-2, -2));
    st.insert(make_pair(INF, INF));
  }
  void insert(int x) {
    int L = x, R = x;
    auto itr1 = st.lower_bound(make_pair(x, 0));
    if ((*itr1).first == x + 1) {
      R = (*itr1).second;
      st.erase(itr1);
    }
    auto itr2 = prev(st.lower_bound(make_pair(x, 0)));
    if ((*itr2).second == x - 1) {
      L = (*itr2).first;
      st.erase(itr2);
    }
    st.insert(make_pair(L, R));
  }
  void erase(int x) {
    auto itr = prev(st.lower_bound(make_pair(x, INF)));
    int L = (*itr).first;
    int R = (*itr).second;
    st.erase(itr);
    if (L < x) {
      st.insert(make_pair(L, x - 1));
    }
    if (x < R) {
      st.insert(make_pair(x + 1, R));
    }
  }
  int mex() {
    auto itr = st.lower_bound(make_pair(0, 0));
    if ((*itr).first > 0) {
      return 0;
    } else {
      return (*itr).second + 1;
    }
  }
};
struct mex_multiset {
  map<int, int> mp;
  mex_set st;
  mex_multiset() {}
  void insert(int x) {
    if (mp.count(x) == 0) {
      st.insert(x);
    }
    mp[x]++;
  }
  void erase(int x) {
    mp[x]--;
    if (mp[x] == 0) {
      st.erase(x);
      mp.erase(x);
    }
  }
  int mex() { return st.mex(); }
};

void solve() { 
  int N, L, R; 
  cin >>  N >> L >> R;
  vector<int>dp(N+1,0);
  mex_multiset st;
  vector<vector<pair<int,int>>> P(N*N);
  for(int i=1;i<=N;i++){
    if(i >=L){
      for(int j =0;j<=i-L;j++){
        st.insert(dp[j]^dp[i-L-j]);
        P[dp[j]^dp[i-L-j]].push_back(make_pair(i,j));
      }
    }
    dp[i]  =st.mex();
    if(i>=R){
      for(int j=0;j<=i-R;j++){
        st.erase(dp[j]^dp[i-R-j]);
      }
    }
  }
  int p;
  if(dp[N] >0){
    cout<<"First"<<endl;
    p = 0;
  }else{
    cout<<"Second"<<endl;
    p=1;
  }
  vector<bool>c(N,true);
  while(true){
    if(p==0){
      vector<int>A ={0};
      vector<int>B;
      for(int i =0;i<N;i++){
        if(c[i]){
          A.back()++;
          if(A.back()==1){
            B.push_back(i);
          }
        }else{
          if(A.back()!=0){
            A.push_back(0);
          }
        }
      }
      if(A.back()==0){
        A.pop_back();
      }
      int cnt=A.size();
      int g=0;
      for(int i =0;i<cnt;i++){
        g^=dp[A[i]];
      }
      int z  =31-__builtin_clz(g);
      int a =0;
      for(int i=0;i<cnt;i++){
        if((dp[A[i]] >> z&1)==1){
          a=i;
        }
      }
      int nxt= g^dp[A[a]];
      auto itr= upper_bound(P[nxt].begin(),P[nxt].end(),make_pair(A[a],INF));
      int s =(*prev(itr)).first;
      int l  =(*prev(itr)).second;
      int r = s - L - l;
      int x = B[a] + l;
      int y = A[a] - r - l;
      cout<<x+1<<' '<<y<<endl;
      for(int i =0;i<y;i++){
        c[x+i]=false;
      }
    }
    if(p==1){
      int a, b;
      cin >> a >> b;
      if(a==0&& b==0){
        break;
      }
      a--;
      for(int i =0;i<b;i++){
        c[a+i] =false;
      }
    }
    p=1-p;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
