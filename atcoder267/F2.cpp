#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  vector<int> d1(N, -1);
  d1[0] = 0;
  queue<int> Q1;
  Q1.push(0);
  int s;
  while (!Q1.empty()){
    int v = Q1.front();
    Q1.pop();
    s = v;
    for (int w : E[v]){
      if (d1[w] == -1){
        d1[w] = d1[v] + 1;
        Q1.push(w);
      }
    }
  }
  vector<int> p2(N, -1);
  vector<int> d2(N, -1);
  d2[s] = 0;
  queue<int> Q2;
  Q2.push(s);
  int t;
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    t = v;
    for (int w : E[v]){
      if (d2[w] == -1){
        p2[w] = v;
        d2[w] = d2[v] + 1;
        Q2.push(w);
      }
    }
  }
  vector<int> p3(N, -1);
  vector<int> d3(N, -1);
  d3[t] = 0;
  queue<int> Q3;
  Q3.push(t);
  while (!Q3.empty()){
    int v = Q3.front();
    Q3.pop();
    for (int w : E[v]){
      if (d3[w] == -1){
        p3[w] = v;
        d3[w] = d3[v] + 1;
        Q3.push(w);
      }
    }
  }
  vector<vector<int>> pp1(LOG, vector<int>(N, -1));
  vector<vector<int>> pp2(LOG, vector<int>(N, -1));
  pp1[0] = p2;
  pp2[0] = p3;
  for (int i = 0; i < LOG - 1; i++){
    for (int j = 0; j < N; j++){
      if (pp1[i][j] != -1){
        pp1[i + 1][j] = pp1[i][pp1[i][j]];
      }
      if (pp2[i][j] != -1){
        pp2[i + 1][j] = pp2[i][pp2[i][j]];
      }
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int U, K;
    cin >> U >> K;
    U--;
    if (d2[U] >= K){
      for (int j = 0; j < LOG; j++){
        if ((K >> j & 1) == 1){
          U = pp1[j][U];
        }
      }
      cout << U + 1 << endl;
    } else if (d3[U] >= K){
      for (int j = 0; j < LOG; j++){
        if ((K >> j & 1) == 1){
          U = pp2[j][U];
        }
      }
      cout << U + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
