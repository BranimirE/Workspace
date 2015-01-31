/*
ID: brani.e2
PROG: milk6
LANG: C++11
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
const int MAXN = 33;
int n, m;
Number g[MAXN][MAXN];
struct Edge {
  Number cost;
  int u, v;
  int index;
};
bool operator < (Edge a, Edge b) {
  if (a.cost != b.cost)
    return a.cost > b.cost;
  return a.index < b.index;
}
int parent[MAXN];
bool bfs(int s, int t) {
  memset(parent, -1, sizeof(parent));
  queue<int> q;
  parent[s] = -2;//Para evitar ciclos
  q.push(s);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for (int v = 1; v <= n; v++)
      if (g[u][v] > 0 && parent[v] == -1) {
	parent[v] = u;
	if (v == t) return true;
	q.push(v);
      }
  }
  return false;
}
Number max_flow(int s, int t) {
  Number totalflow = 0, flow;
  while (bfs(s, t)) {
    flow = LLONG_MAX;
    int u, v;
    v = t;
    while ((u = parent[v]) > 0) {
      flow = min(flow, g[u][v]);
      v = u;
    }

    v = t;
    while ((u = parent[v]) > 0) {
      g[u][v] -= flow;
      g[v][u] += flow;
      v = u;
    }
    totalflow += flow;
  }
  return totalflow;
}
vector<Edge> edges;
int main() {
  freopen("milk6.in", "r", stdin);
  freopen("milk6.out", "w", stdout);
  memset(g, 0, sizeof(g));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    Number cost;
    scanf("%d %d %lld", &u, &v, &cost);
    edges.push_back({cost, u, v, i + 1});
    g[u][v] += cost;
  }
  sort(edges.begin(), edges.end());
  Number totalflow = max_flow(1, n);
  printf("%lld ", totalflow); 
  vector<int> ans;
  
  for (int i = 0; i < edges.size(); i++) {
    auto e = edges[i];
    memset(g, 0, sizeof(g));
    
    for (auto edg: edges)
      g[edg.u][edg.v] += edg.cost;
    
    for (int idx: ans)
      g[edges[idx].u][edges[idx].v] -= edges[idx].cost;
    
    g[e.u][e.v] -= e.cost;
    
    if ((totalflow - e.cost) == max_flow(1, n)) {
      ans.push_back(i);
      totalflow -= e.cost;
    } 
    if (totalflow == 0) break;
    
  }
  for (int &e: ans)
    e = edges[e].index;
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d\n", ans[i]);

  
  return 0;
}
