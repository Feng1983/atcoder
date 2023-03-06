#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;

vector<long long> operator +(vector<long long>A, vector<long long> B){
  int n = A.size(), m = B.size();
  vector<long long> C(max(n,m), 0);
  for(int i = 0;i<n;i++){
    C[i]+=A[i];
  }
  for(int i = 0;i<M;i++){
    C[i]+=B[i];
    if(C[i]>=MOD){
      C[i]-=MOD;
    }
  }
  return C;
}
pair<vector<long long>, vector<long long>> dfs(vector<vector<long long>>&F, int L, int R){
  if(R-L==1){
    return make_pair(vector<long long>(1,1),F[L]);
  }
  else{
    int m =(L+R)/2;
    pair<vector<long long>, vector<long long>> ans1=dfs(F, L, m);
    pair<vector<long long>, vector<long long>> ans2= dfs(F, m, R);
    return make_pair(ans1.first+atcoder::convolution(ans1.second, ans2.first), atcoder::convolution(ans1.second, ans2.second));
  }
}
 int main(){
   int N;
   cin >> N;
   vector<int>P(N);
   for(int i =1;i<N;i++){
     cin >>P[i];
     P[i]--;
   }
   vector<vector<int>> c(N);
   for(int i=1;i<N;i++){
     c[P[i]].push_back(i);
   }
   vector<int> sz(N,1);
   for(int i =N-1;i>=1;i--){
     sz[P[i]]+=sz[i];
   }
   for(int i  =0;i<N;i++){
     for(int &j: c[i]){
       if(sz[j] >sz[c[i][0]]){
         swap(c[i][0],j);
       }
     }
   }
   vector<bool> head(N,false);
   head[0] =true;
   for(int i =0;i<N;i++){
     for(int j:c[i]){
       if(j!=c[i][0]){
         head[j]=true;
       }
     }
   }
   vector<vector<long long>> dp(N);
   for(int i= N-1;i>=0;i--){
     if(head[i]){
       vector<int>S;
       S.push_back(i);
       while(!c[S.back()].empty()){
         int v =S.back();
         S.push_back(c[v][0]);
       }
       int cnt= S.size();
       vector<vector<long long>> F(cnt);
       for(int j=0;j<cnt;j++){
         queue<vector<long long>> Q;
         for(int k: c[S[j]]){
           if(k!=c[S[j]][0]){
             Q.push(dp[k]);
           }
         }
         if(Q.empty()){
           F[j] ={1};
         }else{
           while(Q.size()>=2){
             vector<long long> f =Q.front();
             Q.pop();
             vector<long long> g =Q.front();
             Q.pop();
             Q.push(atcoder::convolution(f,g));
           }
           F[j] = Q.front();
         }
       }
       pair<vector<long long>, vector<long long>> ans = dfs(F, 0,cnt);
       ans.first.insert(ans.first.begin(),0);
       dp[i] =ans.first+ans.second;
     }
   }
   dp[0].resize(N+1);
   for(int i = 0;i<=N;i++){
     cout<< dp[0][i] <<endl;
   }
 }
