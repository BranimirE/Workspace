/*
ID: brani.e2
PROG:fence6 
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>

#define MAXN 101
#define INF 1<<28
using namespace std;

int N, idseg, nid;
int L[MAXN];
int id[MAXN][2];
int a[MAXN][2][10];
vector<pair<int, int> > g[MAXN * 2];
bool v[MAXN * 2][MAXN * 2];

int dist[MAXN * 2];
bool visitado[MAXN * 2];
set<pair<int,int> > cola;
void dijkstra(int ini){
	for(int i = 1; i <= nid; ++i){
		dist[i] = INF;
		visitado[i] = false;
	}
	dist[ini] = 0;
	cola.insert(make_pair(0, ini));
	int act, ady, peso;
	while(!cola.empty()){
		act = (*cola.begin()).second;
		cola.erase(cola.begin());
		if(visitado[act])continue;
		visitado[act] = true;
		for(int i = 0; i < g[act].size(); ++i){
			ady = g[act][i].second;
			peso = g[act][i].first;
			if(v[act][i] && !visitado[ady] && dist[act] + peso < dist[ady]){
				dist[ady] = dist[act] + peso;
				cola.insert(make_pair(dist[ady], ady));
			}
		}
	}
}

int main(){
	ifstream cin("fence6.in");
	ofstream cout("fence6.out");
	cin >> N;
	for(int reg = 1; reg <= N; reg++){
		cin >> idseg;
		cin >> L[idseg] >> a[idseg][0][0] >> a[idseg][1][0];
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= a[idseg][i][0]; ++j)
				cin >> a[idseg][i][j];
	}
	memset(id, -1, sizeof(id));
	nid = 0;
	for(int i = 1; i <= N; ++i)
		for(int j = 0; j < 2; ++j)
			if(id[i][j] == -1){
				id[i][j] = ++nid;
				for(int k = 1; k <= a[i][j][0]; ++k){
					int e = a[i][j][k];
					for(int m = 0; m < 2; ++m)
						if(id[e][m] == -1)
							for(int n = 1; n <= a[e][m][0]; ++n)
								if(a[e][m][n] == i){
									id[e][m] = id[i][j];
									break;
								}
				}
			}
	for(int i = 1; i <= N; ++i){
		int a = id[i][0], b = id[i][1] , d = L[i];
		g[a].push_back(make_pair(d, b));
		g[b].push_back(make_pair(d, a));
	}
	for(int i = 1; i <= nid; ++i)
		for(int j = 0; j < g[i].size(); ++j)
			v[i][j] = true;
	int ans = INF;
	for(int i = 1; i <= nid; ++i){
		for(int j = 0; j < g[i].size(); ++j){
			v[i][j] = false;
			int ady = g[i][j].second;
			int peso = g[i][j].first;
			for(int k = 0; k < g[ady].size(); ++k)
				if(g[ady][k].second == i){
					v[ady][k] = false;
					dijkstra(i);
					ans = min(ans, peso + dist[ady]);
					v[ady][k] = true;
				}
			v[i][j] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
