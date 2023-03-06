#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  multiset<int> st;
  while(q--){
    int type;
    cin >> type;
    if(type==1){
      int x;
      cin >> x;
      st.insert(x);
    }else if(type==2){
      int x, c;
      cin >> x >> c;
      while(c--){
        auto it=st.find(x);
        if(it==st.end()){
          break;
        }
        st.erase(it);
      }
    }else if(type==3){
      cout<<(*prev(st.end())-*st.begin());
      cout<<endl;
    }
  }
  return 0;
}
