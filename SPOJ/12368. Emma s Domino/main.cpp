#include <bits/stdc++.h>
#define INF (1<<28)
using namespace std;
int n, h;
int d[1234];
vector<int > g[1234];
int dist[1234];
int main() {
  while(scanf("%d%d", &n, &h) == 2 && !(n == -1 && h == -1)) {
    d[0] = 0;
    g[0].clear();
    for (int i = 1; i < n; i++) {
      d[i] = d[i - 1];
      int tmp;
      scanf("%d", &tmp);
      d[i] += tmp;
      g[i].clear();
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
	if ((d[j] - d[i]) <= ((j - i) * h)) {
	  g[i].push_back(j);
	}	    
      }
    }
    set<pair<int, int> > q;
    q.insert(make_pair(0, 0));
    fill(dist, dist + n, INF);
    dist[0] = 0;
    while(!q.empty()) {
      int u = q.begin()->second;
      q.erase(q.begin());
      for (int i = 0; i < g[u].size(); i++) {
	int v = g[u][i];
	int w = v - u - 1;
	if (dist[u] + w < dist[v]) {
	  q.erase(make_pair(dist[v], v));
	  dist[v] = dist[u] + w;
	  q.insert(make_pair(dist[v], v));
	}
      }
    }
    /*
    //Dijkstra Fast!!!
    vector<int> dist(n, INF); dist[0] = 0;
    queue<int> q; q.push(0);
    vector<int> in_queue(n, 0); in_queue[0] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop(); in_queue[u] = 0;
      for (int j = 0; j < g[u].size(); j++) {
	int v = g[u][j], weight_u_v = v - u - 1;
	if (dist[u] + weight_u_v < dist[v]) {
	  dist[v] = dist[u] + weight_u_v;
	  if (!in_queue[v]) {
	    q.push(v);
            in_queue[v] = 1;
	  }
	}
      }
      }*/
    if (dist[n - 1] != INF)
      printf("%d\n", dist[n - 1]);
    else
      printf("-1\n"); 
  }
  return 0;
}
