/*
ID: brani.e2
PROG: fence
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>

#define MAXN 500

using namespace std;

vector<int> grafo[MAXN + 1];
int grado[MAXN+1];
int visitado[MAXN+1][MAXN+1];
int maxnodo;
int obtenerInicio(){
	int res = 0,i;
	for(int i = 1; i <= maxnodo; i++)
		if(grado[i]){
			res = i;
			break;
		}
	for(int i = 1; i <= maxnodo; i++)
		if(grado[i]!=0 && grado[i]%2 == 1){
			res = i;
			break;
		}
	return res;
}
vector<int> circuito;
void encontrarcircuito2(int ini){
	for(int i = 0; i < grafo[ini].size(); i++)
		if(visitado[ini][grafo[ini][i]]){//si tiene adyacentes
			visitado[ini][grafo[ini][i]]--;
			visitado[grafo[ini][i]][ini]--;
			encontrarcircuito2(grafo[ini][i]);
		}
	circuito.push_back(ini);
}

void encontrarcircuito(int ini){
	stack<int> pila;
	pila.push(ini);
	while(!pila.empty()){
		int e = pila.top();
		if(grafo[e].size() <= 0){
			pila.pop();
			circuito.push_back(e);
		}
		else{
			int f = grafo[e][0];
			pila.push(f);
			grafo[f].erase(find(grafo[f].begin(),grafo[f].end(),e));
			grafo[e].erase(grafo[e].begin());
		}
	}
}
int main() {
	ifstream cin("fence.in");
	ofstream cout("fence.out");
	int f,a,b;
	cin >> f;
	maxnodo = 0;
	while(f--){
		cin >> a >> b;
		maxnodo = max(maxnodo,max(a,b));
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		visitado[a][b]++;
		visitado[b][a]++;
		grado[a]++;
		grado[b]++;
	}
	for(int i = 1; i<=maxnodo; i++)
		sort(grafo[i].begin(),grafo[i].end());

	encontrarcircuito2(obtenerInicio());
	for(int i = circuito.size()-1; i >= 0; i--)
		cout << circuito[i]<<endl;
	return 0;
}
