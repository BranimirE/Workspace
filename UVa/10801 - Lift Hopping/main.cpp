#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
#define oo 1<<30
int ini, fin, n;
string garbage;

struct Nodo{
	int peso;
	int destino;
	int asc;
	Nodo(){
		peso = destino = asc = 0;
	}
	Nodo(int _dest, int _peso, int _asc){
		destino = _dest;
		peso = _peso;
		asc = _asc;
	}
	bool operator < (const Nodo otro) const {
		return peso  > otro.peso;
	}
};

int t[5];
vector<int> asc[5];
bool perm[5][100];
int d[100];
bool v[100];
priority_queue<Nodo> q;
vector<int> leerlinea(){
	vector<int> v;
	string linea;
	getline(cin,linea);
	stringstream ss(linea);
	int tmp;
	while(ss >> tmp)
		v.push_back(tmp);
	return v;
}
int act, asensor, ady, incr;
int main(){
	freopen("entrada.in","r",stdin);
	while(cin >> n >> fin){
		getline(cin,garbage);
		for(int i = 0; i < n; ++i)
			cin >> t[i];

		getline(cin,garbage);

		memset(perm, false, sizeof perm);
		for(int i = 0; i < n; ++i){
			asc[i] = leerlinea();
			for(int j = 0; j < asc[i].size(); ++j)
				perm[i][asc[i][j]] = true;
		}
		
		for(int i = 0; i < 100; ++i){
			d[i] = oo;
			v[i] = false;
		}

		d[0] = 0;
		for(int i = 0; i < n; ++i)	
			if(perm[i][0])
				q.push(Nodo(0,0,i));

		pair<int,int> padre[100];
		for(int i = 0; i < 100; i++){
			padre[i].first = -1;
			padre[i].second = -1;
		}
		while(!q.empty()){
			act = q.top().destino; // piso actual
			asensor = q.top().asc;
			q.pop();
			if(v[act])continue;
			// ahora los adyacentes
			//mismo asensor
/*			for(int i = 0; i < asc[asensor].size(); ++i){
				ady = asc[asensor][i];
				if(!v[ady] && d[act]+ abs(act-ady)*t[asensor] < d[ady]){
					d[ady] = d[act] + abs(act-ady)*t[asensor];
					q.push(Nodo(ady, d[ady], asensor));
				}
			}*/
			//pasando a los otros asensores
			for(int a = 0; a < n; ++a){

				if( a != asensor ) 
					incr = 60;
				else
					incr = 0;

				if( perm[a][act] ) // si en el asensor a se pude parar en el piso actual 
					for(int i = 0; i < asc[a].size(); ++i){
						ady = asc[a][i];
						if(!v[ady] && d[act]+ abs(act-ady)*t[a] + incr < d[ady]){
							d[ady] = d[act] + abs(act-ady)*t[a] + incr;

							padre[ady].first = act;
							padre[ady].second = a;

							q.push(Nodo(ady, d[ady], a));
						}
					}
			}
		}
		cout << "camino invertido" << endl;
		int parent = fin;
		cout << fin;
		while(padre[parent].first != -1){
			cout << " " << padre[parent].first<<"("<< padre[parent].second<<") ";
			parent = padre[parent].first;
		}
		cout << endl;

		if(d[fin] != oo)
			cout << d[fin] << endl;
		else 
			cout << "IMPOSSIBLE"<<endl;
		
	}
	return 0;
}
