#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

#define LVL 17
#define MAXN (1<<LVL)
#define MAXK 101

vector<int> t[MAXN];
int dist[MAXN];
bool visitado[MAXN];
int producto[MAXN];
int ans, mejordist;
void calculardist(int u) {
  for (int i = 0; i < sz(t[u]); i++) {
    int v = t[u][i];
    if (dist[v] == -1) {
      dist[v] = dist[u] + 1;
      calculardist(v);
    }
  }
}
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
  for (int i = 0; i < sz(t[nodo]); i++) {
    int ady = t[nodo][i];
    if (!visitado[ady]) {
      visitado[ady] = true;
      solve(ady, min(lejos, dist[ady]), busca);
    }
  }
}

vector<int> tienen[MAXK];
int main() {
  int rey;
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%d", &rey);
  rey--;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    t[u].pb(v);
    t[v].pb(u);
  }
  for (int i = 0; i < n; i++) {
    int prod;
    scanf("%d", &prod);
    tienen[prod].pb(i);
    producto[i] = prod;
  }
  memset(dist, -1, sizeof(dist));
  dist[rey] = 0;
  calculardist(rey);
  
  int queries;
  scanf("%d", &queries);
  while (queries--) {
    int chef, busca;
    scanf("%d %d", &chef, &busca);
    chef--;
    ans = -1;
    mejordist = 0;
    memset(visitado, false, sizeof(visitado));
    visitado[chef] = true;
    solve(chef, dist[chef], busca);
    printf("%d\n", ans + 1);
  }
  return 0;
}
