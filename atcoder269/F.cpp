#include<bits/stdc++.h>
using namespace std;


const long long HALF=499122177;
const long long MOD= 998244353;

long long ap(long long L, long long d, long long cnt){

  long long R = (L+(d%MOD)*((cnt-1)%MOD))%MOD;
  return (L+R)%MOD *cnt%MOD*HALF%MOD;
}


long long solve(long long N, long long M, long long A, long long B){
  
  long long S1= ap(1,1,B);
  long long ans1 = ap(S1, M*B, A);
  long long ans2= 0;
  if(A%2==1){
    ans2+=MOD-(B/2);
  }
  if(B%2==1){
    ans2+=MOD-(A/2)*M%MOD;
  }
  if(A%2==1 && B%2==1){
    ans2+=M*(A-1)+B;
  }
  ans2%=MOD;
  return (ans1+ans2)*HALF%MOD;

}
int main(){
  int n,m;
  cin >> n >> m;
  int Q;
  cin >> Q;
  for(int i = 0;i<Q;i++){
    int A, B , C, D;
    cin >> A >> B >>C >> D;
    A--;
    C--;
    long long ans1= solve(n,m, A,C);
    long long ans2 = solve(n,m,A,D);
    long long ans3 = solve(n, m, B,C);
    long long ans4 = solve(n,m,B,D);
    cout<<(ans1-ans2-ans3+ans4+MOD*2)%MOD<<endl;
  }
}


