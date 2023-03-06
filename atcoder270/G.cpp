#include<bits/stdc++.h>
#include <cmath>
using namespace std;

const int SQRT=30000;

long long modpow(long long a, long long b, long long mod){
  long long ans =1;
  while(b>0){
    if(b&1){
      ans*=a;
      ans%=mod;
    }
    a*=a;
    a%=mod;
    b/=2;
  }
  return ans;
}

long long modinv(long long a, long long mod){
  return modpow(a, mod-2, mod);
}
int main(){
  int T;
  cin >>T;
  for(int i = 0;i<T;i++){
    long long P, A, B, S, G;
    cin >> P >> A >> B >>S >>G;
    if(A==0){
      if(G==S){
        cout<<0<<endl;
      }else if(G==B){
        cout<<1<<endl;
      }else{
        cout<<-1<<endl;
      }
    }else if(A==1){
      if(B==0){
        if(G==S){
          cout<<0<<endl;
        }else{
          cout<<-1<<endl;
        }
      }else {
        cout<<(G-S+P)%P *modinv(B,P)%P<<endl;
      }
    }
    else{
      long long c =B*modinv((P+1-A)%P,P)%P;
      S= (S+P-c)%P;
      G= (G+P-c)%P;
      if(S==0){
        if(G==0){
          cout<<0<<endl;
        }else{
          cout<<-1<<endl;
        }
      }else if(G==0){
        cout<<-1<<endl;
      }else{
        G=G*modinv(S,P)%P;
        vector<long long> POW(SQRT);
        POW[0]=1;
        for(int j =0;j<SQRT-1;j++){
          POW[j+1] = POW[j]*A%P;
        }
        unordered_map<long long, int> mp;
        for(int j=SQRT-1;j>=0;j--){
          mp[POW[j]]=j;
        }
        long long A2 = modpow(modinv(A,P),SQRT,P);
        int ans =0;
        while(true){
          if(mp.count(G)==1){
            cout<<ans+mp[G]<<endl;
            break;
          }
          G*=A2;
          G%=P;
          ans+=SQRT;
          if(ans > P*2){
            cout<<-1<<endl;
            break;
          }
        }
      }
    }
  }

}
