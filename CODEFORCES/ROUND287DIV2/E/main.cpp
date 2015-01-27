#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
const int MAXN = 100010;
int n, m;
int from[MAXN], to[MAXN], estado[MAXN];
vector<pair<int, int>> g[MAXN];
int dist[MAXN], cnt[MAXN];
int funcionan;
int parent[MAXN];
void solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    int u, v, est, newdist;
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
	u = q.front(), q.pop();
	for (auto e: g[u]) {
	    v = e.first;
	    est = estado[e.second];
	    newdist = dist[u] + 1;
	    if (dist[v] == -1) {
		dist[v] = newdist;
		cnt[v] = cnt[u] + est;
		parent[v] = u;
		q.push(v);
	    } else if (dist[v] == newdist) {
		if ((cnt[u] + est) > cnt[v]) {
		    cnt[v] = cnt[u] + est;
		    parent[v] = u;
		    q.push(v);
		}
	    }
	}
    }
    int ans = dist[n] + funcionan - 2 * cnt[n];
    printf("%d\n", ans);
    memset(cnt, 0, sizeof(cnt));
    u = n;
    while (true) {
	v = parent[u];
	if (v == -1) break;
	for (auto e: g[u])
	    if (e.first == v)
		cnt[e.second] = 1;//In the best path
	u = v;
    }
    forn (i, m) {
	if (cnt[i]) {//In the path
	    if (estado[i] == 0)//Repair it
		printf("%d %d 1\n", from[i], to[i]);
	} else {
	    if (estado[i] == 1)//Blow it
		printf("%d %d 0\n", from[i], to[i]);
	}
    }
}
int main() {
    scanf("%d %d", &n, &m);
    funcionan = 0;
    forn (i, m) {
	scanf("%d %d %d", from + i, to + i, estado + i);
	g[from[i]].eb(to[i], i);
	g[to[i]].eb(from[i], i);
	funcionan += estado[i];
    }
    solve();
    return 0;
}
