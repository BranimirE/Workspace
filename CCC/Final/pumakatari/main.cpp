#include <bits/stdc++.h>
#define INF 1<<28
using namespace std;
typedef long long int Number;
int n, m;
vector<pair<int, int > > g[123];
int distancia(int S, int T){
	vector<int> dist(n, INF); dist[S] = 0;
	queue<int> q; q.push(S);
	vector<int> in_queue(n, 0); in_queue[S] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		in_queue[u] = 0;
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j].first, weight_u_v = g[u][j].second;
			if (dist[u] + weight_u_v < dist[v]) {
				dist[v] = dist[u] + weight_u_v;
				if (!in_queue[v]) {
					q.push(v);
					in_queue[v] = 1;
				}
			}
		}
	}
	if (dist[T] != INF)
		return dist[T];
	return -1;
}
Number dp[123][1005];
Number solve(int act, int dist, int fin){
	if(dist == 0 && act == fin)
		return 1;
	if(dist < 0)
		return 0;
	Number &ans = dp[act][dist];
	if(ans != -1)return ans;
	ans = 0;
	int ady, peso;
	for(int i = 0; i < g[act].size(); i++){
		ady = g[act][i].first;
		peso = g[act][i].second;
		ans += solve(ady, dist - peso, fin);
	}
	return ans;
}
int main(){
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n >> m;
		int a, b;
		cin >> a >> b;
		a--; b--;
		for(int i = 0; i < n; i++)
			g[i].clear();
		for(int i = 0; i < m; i++){
			int u, v, dist;
			cin >> u >> v >> dist;
			u--; v--;
			g[u].push_back(make_pair(v, dist));
			g[v].push_back(make_pair(u, dist));
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(a, distancia(a, b), b) << endl;
	}

	return 0;
}
