#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iomanip>
#include <set>

#define MAXN 110

using namespace std;

int ancho, alto;

char g[MAXN * 2][MAXN * 2];
int d[MAXN * 2][MAXN * 2];

int dx[4] = {2, 0, -2, 0};
int dy[4] = {0, 2, 0 ,-2};
int dxv[4] = {1, 0, -1, 0};
int dyv[4] = {0, 1,  0, -1};

queue<pair<int,int> > cola;

bool isvalid(int i, int j){
	return i>=0 && i <alto && j >= 0 && j < ancho;
}
void  solve(int i, int j){
	memset(d, -1, sizeof d);
	d[i][j] = 0;
	cola.push(make_pair(i,j));
	while(!cola.empty()){
		i = cola.front().first;
		j = cola.front().second;
		cola.pop();
		for(int a = 0; a < 4; a++){
			int ai = i + dx[a], vi = i + dxv[a];
			int aj = j + dy[a], vj = j + dyv[a];
			if(isvalid(vi,vj) && g[vi][vj]=='0' && isvalid(ai,aj) && d[ai][aj] == -1){
				d[ai][aj] = d[i][j] + 1;
				cola.push(make_pair(ai,aj));
			}
		}
		
	}
}
int main(){
//	freopen("entrada.in", "r", stdin);
	while(cin >> ancho >> alto && !(ancho == 0 && alto == 0)){
		ancho = ancho * 2 - 1;
		alto = alto * 2 - 1;
		gets(g[0]);
		for(int i = 0; i < alto; i++)
			gets(g[i]);
		solve(0,0);
		/*for(int i = 0; i < alto; i+=2, cout << endl)
			for(int j = 0; j < ancho; j+=2)
				cout << setw(3) << d[i][j]  ;
		*/	
			cout << d[alto-1][ancho-1]  +  1<< endl;
		
	}
	return 0;
}
