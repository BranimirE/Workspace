/*
 ID: brani.e2
 PROG: ditch
 LANG: C++
*/
#include <bits/stdc++.h>

#define MAX 205
#define oo (1LL<<50)
using namespace std;

typedef long long int Number;

int n, m;
Number res[MAX][MAX];
vector<int> g[MAX];
int p[MAX];
bool aument(int s, int t){
  queue<int> q;
  q.push(s);
  memset(p, -1, sizeof(p));
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int i = 0; i < g[u].size(); i++){
      int v = g[u][i];
      if(res[u][v] && v != s && p[v] == -1){
        p[v] = u;
        if(v == t) return true;
        q.push(v);
      }
    }
  }
  return false;
}
Number maxFlow(int s, int t){
  Number mf = 0, f;
  while(aument(s, t)){
    int cur = t;
    f = oo;
    while(p[cur] != -1){
      f = min(f, res[p[cur]][cur]);
      cur = p[cur];
    }
    cur = t;
    while(p[cur] != -1){
      int u = p[cur], v = cur;
      res[u][v] -= f;
      res[v][u] += f;
      cur = u;
    }
    mf += f;
  }
  return mf;
}

int main(){
  freopen("ditch.in", "r", stdin);
  freopen("ditch.out", "w", stdout);
  cin >> m >> n;
  memset(res, 0, sizeof(res));
  while(m--){
    int u, v;
    Number p;
    cin >> u >> v >> p;
    res[u][v] += p;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << maxFlow(1, n) << endl;
  return 0;
}
