/*
 ID: brani.e2
 PROG: stall4
 LANG: C++
*/
#include <bits/stdc++.h>
#define MAX 405
#define oo (1<<28)
using namespace std;
vector<int> g[MAX];
int res[MAX][MAX];
int n, m;
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
        if(v == t)return true;
        q.push(v);
      }
    }
  }
  return false;
}
int maxFlow(int s, int t){
  int mf = 0;
  int f;
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
  freopen("stall4.in", "r", stdin);
  freopen("stall4.out", "w", stdout);
  scanf("%d%d", &n, &m);
  memset(res, 0, sizeof(res));
  int s = n + m + 1;
  int t = s + 1;
  for(int u = 1; u <= n; u++){
    g[s].push_back(u);
    g[u].push_back(s);
    res[s][u] = 1;
    int s;
    scanf("%d", &s);
    while(s--){
      int v;
      scanf("%d", &v);
      v += n;
      g[u].push_back(v);
      g[v].push_back(u);
      res[u][v] = 1;
    }
  }
  for(int u = n + 1; u <= n + m; u++){
    g[u].push_back(t);
    g[t].push_back(u);
    res[u][t] = 1;
  }
  printf("%d\n", maxFlow(s, t));
  
  return 0;
}
