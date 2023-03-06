#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int N = s.size();
  bool ok=true;
  stack<int> st;
  st.push(-1);

  int A=0;
  for(int i=0;i<N;i++){
    if(s[i]=='('){
      st.push(-1);
    }else if(s[i]==')'){
      while(st.top()!=-1){
        A^= 1<<st.top();
        st.pop();
      }
      st.pop();
    }else{
      int p =s[i]-'a';
      if((A>>p&1) ==1){
        ok=false;
        break;
      }
      A|=1<<p;
      st.push(p);
    }
  }
  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
