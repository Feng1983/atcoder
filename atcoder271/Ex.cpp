#include <bits/stdc++.h>
using namespace std;

void solve() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int A, B;
    cin >> A >> B;
    string s;
    cin >> s;
    if (A < 0) {
      A *= -1;
      swap(s[1], s[3]);
      swap(s[0], s[4]);
      swap(s[5], s[7]);
    }
    if (B < 0) {
      B *= -1;
      swap(s[3], s[5]);
      swap(s[2], s[6]);
      swap(s[1], s[7]);
    }
    if (A < B) {
      swap(A, B);
      swap(s[0], s[2]);
      swap(s[3], s[7]);
      swap(s[4],s[6]);
    }
    if(A==0 && B==0){
      cout<<0<<endl;
    }else if(B==0){
      if(s[0]=='1'){
        cout<<A<<endl;
      }else if(s[1]=='1'&& s[7]=='1'){
        if(A%2==0){
          cout<<A<<endl;
        }else{
          if(s[2]=='1'||s[6]=='1'){
            cout<<A+1<<endl;
          }else if(s[4]=='1'){
            cout<<A+2<<endl;
          }else {
            cout<<-1<<endl;
          }
        }
      }else if(s[1]=='1' && s[6]=='1'){
        cout<<A*2<<endl;
      }else if(s[7]=='1'&& s[2]=='1'){
        cout<<A*2<<endl;
      }else{
        cout<<-1<<endl;
      }
    }else if(A==B){
      if(s[1]=='1'){
        cout<<A<<endl;
      }else if(s[0]=='1' &&s[2]=='1'){
        cout<<A*2<<endl;
      }else if(s[0]=='1' && s[3]=='1'){
        cout<<(long long)A*3<<endl;
      }else if (s[2]=='1'&& s[7]=='1'){
        cout<<(long long)A*3<<endl;
      }else{
        cout<<-1<<endl;
      }
    }else{
      if(s[0]=='1'){
        if(s[1]=='1'){
          cout<<A<<endl;
        }else if(s[2]=='1'){
          cout<<A+B<<endl;
        }else if(s[3]=='1'){
          cout<<(long long)A+B*2<<endl;
        }else{
          cout<<-1<<endl;
        }

      }else if(s[1]=='1'){
        if(s[7]=='1'){
          if((A+B)%2==0){
            cout<<A<<endl;
          }else{
            if(s[2]=='1' ||s[6]=='1'){
              cout<<A+1<<endl;
            }else if(s[4]=='1'){
              cout<<A+2<<endl;
            }else {
              cout<<-1<<endl;
            }
          }
        }else if(s[6]=='1'){
          cout<<A*2-B<<endl;
        }else{
          cout<<-1<<endl;
        }
      }else if(s[7]=='1'){
        if(s[2]=='1'){
          cout<<(long long)A*2+B<<endl;
        }else{
          cout<<-1<<endl;
        }
      }else{
        cout<<-1<<endl;
      }
    }
  }

  return 0;
}
