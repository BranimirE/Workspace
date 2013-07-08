#include <iostream>
#include <fstream>
#include <set>
#include <cstring>
#include <vector>
#define oo ((long long int)1)<<50
using namespace std;

long long int d[20005];
bool v[20005];
set<pair<long long int, int> > q;
int nodos,arcos, ini,fin, a, b ;
vector<pair<int,long long int> > grafo[20005];
int act,ady,peso;

int main(){
	//freopen("entrada.in","r",stdin);
	int casos;
	cin >> casos;
	for(int caso = 1; caso <= casos; ++caso){
		cin >> nodos >> arcos >> ini >> fin;
		for(int i = 0; i < nodos; i++)
			grafo[i].clear();

		while(arcos--){
			cin >> a >> b >> peso;
			grafo[a].push_back(make_pair(b, peso));
			grafo[b].push_back(make_pair(a, peso));
		}

		for(int i = 0; i < nodos; ++i){
			d[i] = oo;
			v[i] = false;
		}
		d[ini] = 0;
		q.insert(make_pair(0,ini));

		while(!q.empty()){
			act = (*(q.begin())).second;q.erase(q.begin());
			if(v[act])continue;
			v[act] = true;
			for(int i = 0; i < grafo[act].size(); ++i){
				ady = grafo[act][i].first;
				peso = grafo[act][i].second;
				if(!v[ady] && d[act] + peso < d[ady] ){
					d[ady] = d[act] + peso;
					q.insert(make_pair(d[ady],ady));
				}
			}			
		}
		cout << "Case #"<<caso<<": ";
		if(d[fin] != oo)
			cout << d[fin] << endl;
		else
			cout << "unreachable" << endl;
	}
	return 0;
}

