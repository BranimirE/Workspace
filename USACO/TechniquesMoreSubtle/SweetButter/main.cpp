/*
ID: brani.e2
PROG: butter
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;
#define MAXP 800
#define INF 1<<30
#define Nodo pair<int,int>
int d[MAXP+5][MAXP+5];
int N,P,C,tmp,a,b;
struct cmp{
	bool operator ()(Nodo &a, Nodo &b){
		return a.second > b.second;
	}
};
vector<Nodo> grafo[MAXP+1];
priority_queue<Nodo, vector<Nodo>, cmp > cola;
int dist[MAXP+1];
bool visitado[MAXP+1];
vector<int> vacas;//estan en el pastisal

int dijkstra(int ini){
	for(int i = 0; i <= MAXP; i++){
		dist[i] = INF;
		visitado[i] = false;
	}
	cola.push(make_pair(ini,0));
	dist[ini] = 0;
	int actual,ady,peso;
	while(!cola.empty()){
		actual = cola.top().first;cola.pop();
		if(actual[visitado])continue;
		actual[visitado] = true;
		for(int i = 0; i < grafo[actual].size(); i++){
			ady = grafo[actual][i].first;
			peso = grafo[actual][i].second;
			if(dist[actual]+peso < dist[ady]){
				dist[ady] = dist[actual]+peso;
				cola.push(make_pair(ady,dist[ady]));
			}
		}
	}
	int sol = 0;
	for(int i = 0; i < vacas.size(); i++)
		sol += dist[vacas[i]];// asumimos que siempre existe un camino
	return sol;
}
int main() {
	ifstream cin("butter.in");
	ofstream cout("butter.out");
	cin >> N >> P >> C;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		vacas.push_back(tmp);
	}
	while(C--){
		cin >> a >> b >> tmp;
		grafo[a].push_back(make_pair(b,tmp));
		grafo[b].push_back(make_pair(a,tmp));
	}
	int sol = INF;
	for(int i = 1; i <= P; i++)
		sol = min(sol,dijkstra(i));
	cout << sol << endl;
	return 0;
}
