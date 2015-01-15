#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

#define MAX 10005
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  if(a.second == b.second)
    return a.first < b.first;
  return a.second > b.second;
}
vector<int> g[MAX];
int n, m, a, b;
int num[MAX], low[MAX], p[MAX], dfsRoot, dfsNum;
int articulation[MAX];
void articulationPoint(int u) {
  low[u] = num[u] = ++dfsNum;
  int hijos = 0;
  for(int j = 0; j < g[u].size(); j++) {
    int v = g[u][j];
    if(!num[v]) { //no visitado
      hijos++;
      p[v] = u;
      articulationPoint(v);

      if(low[v] >= num[u]) // es punto de articulacion
        articulation[u]++;
      low[u] = min(low[u], low[v]);
    } else if(num[v] < num[u] && v != p[u])
      low[u] = min(low[u], num[v]);
  }
  if(u == dfsRoot) articulation[u]--;
  if(u == dfsRoot && hijos == 1) articulation[u] = 0;
}
int main() {
  //freopen("in", "r", stdin);
  while(scanf("%d%d", &n, &m) and !(!n && !m)) {
    for(int i = 0; i < n; i++)
      g[i].clear();

    while(scanf("%d%d", &a, &b) and !(a == -1 && b == -1))
      g[a].push_back(b), g[b].push_back(a);

    dfsNum = 0;
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(p, -1, sizeof(p));
    memset(articulation, 0, sizeof(articulation));

    for(int i = 0; i < n; i++)
      if(!num[i]) {
        dfsRoot = i;
        articulationPoint(i);
      }
    vector<pair<int,int> > ans;
    for(int i = 0; i < n; i++)
      ans.push_back(make_pair(i, articulation[i] + 1));
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < m; i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
    puts("");
  }
  return 0;
}
