#include<bits/stdc++.h>
using namespace std;


void solve(){
  int Q;
  cin >> Q;
  vector<int>seq={0};
  vector<int>pr={-1};
  int curr=0;
  map<int,int> mp;
  for(int i=0;i<Q;i++){
    string S;
    cin >> S;
    if(S=="ADD"){
      int x;
      cin >> x;
      seq.push_back(x);
      pr.push_back(curr);
      curr=seq.size()-1;
    }
    if(S=="DELETE"){
      if(curr!=0){
        curr= pr[curr];
      }
    }
    if(S=="SAVE"){
      int y;
      cin >>y;
      mp[y]  =curr;
    }
    if(S=="LOAD"){
      int z;
      cin >> z;
      curr=mp[z];
    }
    if(curr==0){
      cout<<-1;
    }else{
      cout<<seq[curr];
    }
    if(i<Q-1){
      cout<<' ';
    }
  }
  cout<<endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;

}
