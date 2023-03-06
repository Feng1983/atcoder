#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnt =count(s.begin(),s.end(),'1');
  if(cnt %2==1){
    cout<<-1<<"\n";
    return ;
  }
  if(cnt==0){
    cout<<0<<endl;
    return;
  }
  if(cnt>=4){
    cout<<cnt/2<<endl;
    return ;
  }
  if(n==3){
    if(s[1]=='1'){
      cout<<-1<<"\n";
    }
    else{
      cout<<1<<endl;
    }
    return ;
  }
  vector<int> pos;
  for(int i=0;i<n;i++){
    if(s[i]=='1'){
      pos.push_back(i);
    }
  }
  if(pos[1]-pos[0]>1){
    cout<<1<<endl;
    return;
  }
  if(n==4 && pos[0] ==1){
    cout<<3<<endl;
  }else{
    cout<<2<<endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
