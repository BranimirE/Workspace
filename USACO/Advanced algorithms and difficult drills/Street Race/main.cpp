/*
ID: brani.e2
PROG: race3
LANG: C++
 */
#include <bits/stdc++.h>
#define MAX 55
using namespace std;
int n;
vector<int> g[MAX];
vector<bool> bfs(int from, int ignore = -1) {
  vector<bool> vis(n, false);
  queue<int> q;
  q.push(from);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = true;
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i];
      if (!vis[v] && v != ignore)
	q.push(v);
    }
  }
  return vis;
}
int main(){
  freopen("race3.in", "r", stdin);
  freopen("race3.out", "w", stdout);
  n = 0;
  while(true){
    int tmp;
    scanf("%d", &tmp);
    if(tmp == -1) break;
    
    if(tmp == -2) n++;
    
    if(tmp >= 0)
      g[n].push_back(tmp);
  }
  vector<int> inevitable,  corte;
  vector<bool> A, B;
  for (int node = 1; node <= (n - 2); node++) {
    A = bfs(0, node);
    if (A[n - 1] == false) {
      inevitable.push_back(node);
      B = bfs(node);
      bool iscutpoint = true;
      for (int i = 0; i < n; i++)
	if (A[i] == B[i]) {
	  iscutpoint = false;
	  break;
	}
      if (iscutpoint) corte.push_back(node);
    }
  }
  printf("%d", (int)inevitable.size());
  for (int i = 0; i < (int)inevitable.size(); i++)
    printf(" %d", inevitable[i]);
  printf("\n");

  printf("%d", (int) corte.size());
  for (int i = 0; i < (int)corte.size(); i++)
    printf(" %d", corte[i]);
  printf("\n");
  return 0;
}
