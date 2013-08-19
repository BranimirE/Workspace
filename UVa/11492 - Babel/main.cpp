#include <iostream>
#include <vector>
#include <map>
#include <set>

#define fi first
#define se second
#define MP make_pair
#define MAXN 4000
#define INF 1<<29

using namespace std;

map<string, int> id;

int idd;
vector<pair<char, pair<int, int> > > g[MAXN + 5];
set<pair<int, pair<char, int> > > cola;

int dist[MAXN + 5]['z' + 1];//dist [idioma][letrainicial]
bool v[MAXN + 5]['z' + 1];
void dijkstra(int ini, char inic){
	for(int i = 0; i <= MAXN; i++)
		for(int j = 0; j <= 'z'; j++)
			dist[i][j] = INF, v[i][j] = false;

	int act, ady, peso;
	char caract, carady;
	cola.insert(MP(0, MP(inic, ini)));
	dist[ini][inic] = 0;
	while(!cola.empty()){
		act = (*cola.begin()).se.se;
		caract = (*cola.begin()).se.fi;
		cola.erase(cola.begin());
		if(v[act][caract])continue;
		v[act][caract] =  true;
		for(int i = 0; i < g[act].size(); i++){
			ady = g[act][i].se.fi;
			carady = g[act][i].fi;
			peso = g[act][i].se.se;
			
			if(!v[ady][carady] && caract != carady && dist[act][caract] + peso < dist[ady][carady] ){
				dist[ady][carady] = dist[act][caract] + peso;
				cola.insert(MP(dist[ady][carady], MP(carady,ady)));
			}
		}
	}
}
int main(){
	int aristas, ida, idb;
	string ini, fin, a, b , c;
	while(cin >> aristas && aristas){
		cin >> ini >> fin;
		id.clear();
		for(int i = 0; i < idd; ++i)
			g[i].clear();
		id[ini] = 1;
		id[fin] = 2;
		idd = 3;
		while(aristas--){
			cin >> a >> b >> c;
			if(!id[a])id[a] = idd++;
			if(!id[b])id[b] = idd++;
			ida = id[a];
			idb = id[b];
			g[ida].push_back(MP(c[0], MP(idb, c.size())));
			g[idb].push_back(MP(c[0], MP(ida, c.size())));
		}
		
		dijkstra(1, 0);

		int ans = INF;
		for(char i = 'a'; i <= 'z'; i++)
			ans = min(ans,dist[2][i]);
		for(char i = 'A'; i <= 'Z'; i++)
			ans = min(ans,dist[2][i]);

		if(ans != INF)
			cout << ans << endl;
		else
			cout << "impossivel" << endl;
	}
	return 0;
}
