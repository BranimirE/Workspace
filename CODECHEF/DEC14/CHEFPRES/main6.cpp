#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN 10010
vector<int> g[MAXN];
int producto[MAXN];
int dist[MAXN];
int rey;
int n, k;
void calcualrdist(int u) {
  for (int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i];
    if (dist[v] == -1) {
      dist[v] = dist[u] + 1;
      calcualrdist(v);
    }
  }
}
int ans, mejordist;
bool visitado[MAXN];
void solve(int nodo, int lejos, int busca) {
  if (producto[nodo] == busca) {
    if (ans == -1) {
      ans = nodo;
      mejordist = lejos;
    } else {
      if (lejos > mejordist) {
	ans = nodo;
	mejordist = lejos;
      } else if (lejos == mejordist) {
	ans = min(ans, nodo);
      }
    }
  }
  for (int i = 0; i < sz(g[nodo]); i++) {
    int ady = g[nodo][i];
    if (!visitado[ady]) {
      visitado[ady] = true;
      solve(ady, min(lejos, dist[ady]), busca);
    }
  }
}
int main() {
  scanf("%d %d", &n, &k);
  scanf("%d", &rey);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &producto[i]);
  }
  memset(dist, -1, sizeof(dist));
  dist[rey] = 0;
  calcualrdist(rey);
  int queries;
  scanf("%d", &queries);
  while (queries--) {
    int chef, busca;
    scanf("%d %d", &chef, &busca);
    ans = -2;
    mejordist = 0;
    memset(visitado, false, sizeof(visitado));
    visitado[chef] = true;
    solve(chef, dist[chef], busca);
    printf("%d\n", ans);
  }
  return 0;
}
