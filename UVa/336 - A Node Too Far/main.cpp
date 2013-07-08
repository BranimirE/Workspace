#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

#define MAXN 35

using namespace std;

map<int,int> nom;
vector<int> grafo[MAXN];
int d[MAXN];
int x,N;
int a, b;
queue<int> cola;
void BFS(int ini){
	memset(d,-1, sizeof d);
	cola.push(ini);
	d[ini] = 0;
	while(!cola.empty()){
		int act = cola.front();cola.pop();
		for(int i = 0; i < grafo[act].size(); i++){
			int ady = grafo[act][i];
			if(d[ady] == -1){
				d[ady] = d[act] + 1;
				cola.push(ady);
			}

		}
	}
}
int main(){
	int caso = 1;
	while(cin >> x && x){
		nom.clear();
		N = 1;
		for(int i = 0; i < MAXN; i++)
			grafo[i].clear();


		while(x--){
			cin >> a >> b;
			if(!nom.count(a))
				nom[a] = N++;
			if(!nom.count(b))
				nom[b] = N++;
			grafo[nom[a]].push_back(nom[b]);
			grafo[nom[b]].push_back(nom[a]);
			

		}
		while(cin>>a>>b && !(a==0 && b == 0)){
			BFS(nom[a]);

			int sol=0;
			for(int i = 1; i <N; i++)
				if(d[i]> b || d[i] == -1)
					sol++;
			cout << "Case "<<caso<<": "<<sol<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
			caso++;
		}
	}
	return 0;
}
