#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <vector>
#include <cstring>

#include <queue>

#define MAXN 80010
using namespace std;

map<int, set<int> > filas, cols;

map<int, set<int> >::iterator itm;
set<int>::iterator its;

map<pair<int,int> , int > ids;
int idd = 0; // id disponible

vector<int> grafo[MAXN];
int dist[MAXN];

bool haycamino(int a, int b){

	return a <= b;
}

int main(){
	freopen("entrada.in", "r", stdin);
	int rocas, vf, vc, gf, gc, f, c;
	cin >> rocas >> vf >> vc >> gf >> gc;
	for(int i = 0; i < rocas; ++i){
		cin >> f >> c;
		filas[f].insert(c);
		cols[c].insert(f);
	}

	//por filas
	int columna, fila;
	for(itm = filas.begin(); itm != filas.end(); itm++ ){
		fila = (itm->first);

		int ini, fin, ida, idb;

		its = (itm->second).begin();

		ini = *(its);
		its++;

		for(; its != (itm->second).end(); its++){
			fin = (*its);	
			if(haycamino(ini + 1, fin - 1)){
				cout << "hay camino en columna " << fila << " entre " << ini+1 << " y  " << fin-1 << endl;
				pair<int,int> tmp = make_pair(fila, ini + 1);
				if(ids.count(tmp) == 0) ids[tmp] = idd++;
				ida = ids[tmp];

				tmp = make_pair(fila, fin - 1);
				if(ids.count(tmp) == 0) ids[tmp] = idd++;
				idb = ids[tmp];
				
				grafo[ida].push_back(idb);
				grafo[idb].push_back(ida);

			}
			ini = fin;
		}
	}
// por columnas
	for(itm = cols.begin(); itm != cols.end(); itm++ ){
		columna = (itm->first);

		int ini, fin, ida, idb;

		its = (itm->second).begin();

		ini = *(its);
		its++;

		for(; its != (itm->second).end(); its++){
			fin = (*its);	
			if(haycamino(ini + 1, fin - 1)){
				cout << "hay camino en fila " << columna << " entre " << ini+1 << " y  " << fin-1 << endl;
				pair<int,int> tmp = make_pair(ini + 1, columna);
				if(ids.count(tmp) == 0) ids[tmp] = idd++;
				ida = ids[tmp];

				tmp = make_pair(fin - 1, columna);
				if(ids.count(tmp) == 0) ids[tmp] = idd++;
				idb = ids[tmp];

				grafo[ida].push_back(idb);
				grafo[idb].push_back(ida);

			}
			ini = fin;
		}
	}
	memset(dist, -1, sizeof dist);
	for(int i = 0; i < MAXN; ++i)
		if(grafo[i].size()){
			cout << i << " :  ";
			for(int j = 0; j < grafo[i].size(); j++)
				cout << grafo[i][j] << " ";
			cout << endl;
		}


	return 0;
}
