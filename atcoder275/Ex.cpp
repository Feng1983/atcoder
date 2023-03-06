#include <bits/stdc++.h>
using namespace std;

const int N= 100010;
const long long INF =(long long)4e+18;

int main() {
  int n;
  long long a[N];
  long long b[N];
  int c[N][2];
  int x, y;
  set<int> st;
  set<int>::iterator itr;
  vector<pair<long long, int>> ord;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n ; i++) {
    cin >> b[i];
    ord.push_back({b[i], i});
  }
  b[0] =INF;
  b[n+1] =INF;
  sort(ord.begin(),ord.end());
  for(int i=1;i<=n;i++)for(int j=0;j<2;j++){
    c[i][j]=-1;
  }
  st.insert(0);
  st.insert(n+1);
  for(int i=n-1;i>=0;i--){
    itr =st.upper_bound(ord[i].second);
    y=(*itr);
    itr--;
    x=(*itr);
    if(b[x]<=b[y])c[x][1] =ord[i].second;
    else c[y][0] =ord[i].second;
    st.insert(ord[i].second);
  }
  int k;
  int p[N];
  long long dp0[N];
  long long d[N];
  long long cur;
  multiset<pair<long long, long long>> mst[N];
  multiset<pair<long long ,long long>> ::iterator mstitr;
  pair<long long, long long>z;
  for(int i=1;i<=n;i++)p[i]=i;
  for(int i=0;i<n;i++){
    k=ord[i].second;
    if((c[k][0]==-1)&&(c[k][1]==-1)){
      dp0[k]=a[k]*b[k];
      d[k]  =b[k];
      mst[k].insert({a[k],b[k]});
      continue;
    }
    if(c[k][0]==-1)p[k] =p[c[k][1]];
    else if(c[k][1]==-1)p[k] =p[c[k][0]];
    else if(mst[p[c[k][0]]].size() <mst[p[c[k][1]]].size()){
      p[k] =p[c[k][1]];
      dp0[p[k]]+=dp0[p[c[k][0]]];
      d[p[k]]+=d[p[c[k][0]]];
      mst[p[k]].merge(mst[p[c[k][0]]]);
    }else{
      p[k] = p[c[k][0]];
      dp0[p[k]]+=dp0[p[c[k][1]]];
      d[p[k]]+=d[p[c[k][1]]];
      mst[p[k]].merge(mst[p[c[k][1]]]);
    }
    cur=0;
    while(!mst[p[k]].empty()){
      mstitr = mst[p[k]].begin();
      z=(*mstitr);
      if((z.first<=a[k])||d[p[k]]>=b[k]){
        dp0[p[k]]-=(z.first-cur)*d[p[k]];
        d[p[k]]-=z.second;
        cur = z.first;
        mst[p[k]].erase(mstitr);
      }
      else break;
    }
    if(cur<a[k]){
      dp0[p[k]] -=(a[k]-cur)*d[p[k]];
      cur= a[k];
    }
    mst[p[k]].insert({cur, b[k]-d[p[k]]});
    dp0[p[k]]+=(cur*b[k]);
    d[p[k]]=b[k];
  }
  cout<<dp0[p[ord[n-1].second]]<<endl;
  return 0;
}
