#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <cmath>

#define oo 1 << 30
using namespace std;

queue<int> q;
int d[10000];
int p[] ={1,10,100,1000,10000};
int ini,fin, tmp;
int leer(){
	int ans = 0,t;
	for(int i = 0; i < 4; ++i) cin >> t, ans = ans*10 + t;
	return ans;
}
int main(){
	//freopen("entrada.in","r",stdin);

	int casos,ady;
	cin >> casos;
	for(int caso = 0; caso < casos; ++caso){
		ini = leer();
		fin = leer();
		memset(d,-1, sizeof d);
		cin >> tmp;
		while(tmp--)
			d[leer()] = oo;
		if(d[fin] == oo){
			cout << -1 << endl;
			continue;
		}
		d[ini] = 0;
		q.push(ini);
		while(!q.empty()){
			int act = q.front(); q.pop();
			for(int i = 0; i < 4; ++i){
				int izq = act/p[i+1]*p[i+1];
				int med = (act/p[i])%10;
				int der = act%p[i];
				for(int j = -1; j <= 1; ++j){
					ady = izq + (((med+10+j)%10)*p[i]) + der;
					if(d[ady] == -1){
						d[ady] = d[act] + 1;
						q.push(ady);
					}
				}
			}
		}
		cout<< d[fin] << endl;
	}
	return 0;
}

