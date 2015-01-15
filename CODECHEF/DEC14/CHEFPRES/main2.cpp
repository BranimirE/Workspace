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
int d[MAXN];

bool fcmp(int a,int b) {
  return d[a] < d[b];
}

int vec[LVL][MAXN];
int mn(int i, int j) { // intervalo [i,j)
  int p = 31 - __builtin_clz(j-i);
  return min(vec[p][i],vec[p][j-(1<<p)],fcmp);
}

void mn_init(int n) {
  int mp = 31-__builtin_clz(n);
  forn(p, mp) forn(x, n-(1<<p))
    vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)],fcmp);
}

vector<int> t[MAXN]; // Tree
int pos[MAXN];
int id, pp;
int dist[MAXN];

void dfs(int x) {
  d[x] = id++;
  vec[0][pos[x] = pp++] = x;
  for (int y: t[x]) {
    if (d[y] == -1) {
      dist[y] = dist[x] + 1;
      dfs(y);
      vec[0][pp++] = x;
    }
  }
}

void lcaInit(int n,int raiz) {
  id = pp = 0;
  memset(d,-1,sizeof(d));
  dist[raiz] = 0;
  dfs(raiz);
  mn_init(2*n-1);
}

int lca(int i,int j) {
  int a = pos[i], b = pos[j];
  if (a > b) swap(a,b);
  return mn(a,b+1);
}


bool visitado[MAXN];
int producto[MAXN];
void solve(int nodo, int lejos, int busca, int &ans, int &mejordist) {
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
      solve(ady, min(lejos, dist[ady]), busca, ans, mejordist);
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
  lcaInit(n, rey);
  
  int queries;
  scanf("%d", &queries);
  while (queries--) {
    int chef, busca;
    scanf("%d %d", &chef, &busca);
    chef--;
    int ans = -1;
    int mejordist = 0;
    if (n <= 100) {
      memset(visitado, false, sizeof(visitado));
      visitado[chef] = true;
      solve(chef, dist[chef], busca, ans, mejordist);
    } else {
      for (int obj: tienen[busca]) {
	int acercamiento = dist[lca(chef, obj)];
	if (ans == - 1 || acercamiento > mejordist) {
	  ans = obj;
	  mejordist = acercamiento;
	} else if (acercamiento == mejordist) {
	  ans = min(ans, obj);
	}
      }
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}
