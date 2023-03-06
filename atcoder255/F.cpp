#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& P, vector<int>& I, vector<int>&j,vector<int>&L, vector<int>& R, bool & ok, int l,int r, int p){
  int n  =P.size();
  if(j[P[p]] < l || j[P[p]]>= r){
    ok=false;
    return ;
  }
  if(j[P[p]] > l){
    if(p==n-1){
      ok=false;
      return;
    }
    L[P[p]] =P[p+1];
    dfs(P,I,j,L,R,ok,l,j[P[p]],p+1);
    if(!ok){
      return;
    }
  }
  if(j[P[p]] <r-1){
    int q = p+(j[P[p]]-l+1);
    if(q>=n){
      ok=false;
      return;
    }
    R[P[p]] = P[q];
    dfs(P,I,j,L,R,ok, j[P[p]]+1,r,q);
    if(!ok){
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> I(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> I[i];
    I[i]--;
  }
  if(p[0]!=0){
    cout<<-1<<endl;
  }else{
    vector<int> j(n);
    for(int i = 0 ;i<n;i++){
      j[I[i]] = i;
    }

    set<int> st;
    vector<int>L(n,-1),R(n,-1);
    bool ok=true;
    dfs(p,I,j,L,R,ok,0,n, 0);
    if(!ok){
      cout<<-1<<endl;
    }else{
      for(int  i = 0 ; i< n;i++)
      {
        cout<<L[i]+1<<' '<<R[i]+1<<endl;
      }
    }
  }

  return 0;
}
