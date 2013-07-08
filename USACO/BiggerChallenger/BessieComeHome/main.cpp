/*
ID: brani.e2
PROG: comehome
LANG: C++
 */
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

#define MAXN 'z'+3
#define INF 1<<30
#define Nodo pair<char,int>
struct cmp{
	bool operator() (const Nodo &a, const Nodo &b){
		return a.second > b.second;
	}
};

vector<Nodo> grafo[MAXN];
int dist[MAXN];
bool visitado[MAXN];
priority_queue<Nodo,vector<Nodo>,cmp> cola;

void dijkstra(int ini){
	for(int i = 'A'; i <= 'z'; i++){
		dist[i] = INF;
		visitado[i] = false;
	}

	cola.push(Nodo(ini,0));
	dist[ini] = 0;
	int actual, ady, peso;
	while(!cola.empty()){
		actual = cola.top().first; cola.pop();
		if(!visitado[actual]){
			visitado[actual] = true;
			//cout << "actual "<<(char)actual <<" ->";
			for(int i = 0; i < (int)grafo[actual].size(); i++){
				ady = grafo[actual][i].first;
				peso = grafo[actual][i].second;
				//cout << " dist = "<<dist[actual] << endl;
				//cout <<" "<<(char)ady << " "<<peso<<endl;
				if(!visitado[ady] && dist[actual]+peso < dist[ady]){
					//cout <<" "<<(char)ady ;
					dist[ady] = dist[actual]+peso;
					cola.push(Nodo(ady, dist[ady]));
				}
			}
			//cout << endl;
		}
	}
}

int main() {
	ifstream cin("comehome.in");
	ofstream cout("comehome.out");

	int t, peso;
	char a,b;
	cin >> t;
	while(t--){
		cin >> a >> b >> peso;
		grafo[a].push_back(Nodo(b,peso));
		grafo[b].push_back(Nodo(a,peso));
	}
/*
	for(char i = 'A'; i <= 'z'; i++){
		if(grafo[i].size()>0){
			cout << i << " ->";
			for(int j = 0; j < grafo[i].size(); j++)
				cout << grafo[i][j].first << "("<<grafo[i][j].second<<") ";
			cout << endl;
		}
	}
*/
	dijkstra('Z');
	peso = INF;
	for(char i = 'A'; i < 'Z'; i++){
		//cout << "dist a " <<i << " "<<dist[i]<<endl;
		if(dist[i]<peso){
			a = i;
			peso = dist[i];
		}
	}
	cout << a << " " << peso << endl;

	return 0;
}

