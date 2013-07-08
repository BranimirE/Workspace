/*
ID: brani.e2
PROG: cowtour
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <iomanip>

#define MAXN 155
#define INF 1<<30
using namespace std;

int n;
double x[MAXN], y[MAXN], dist[MAXN][MAXN], may[MAXN];
string cad;
double distancia(int i, int j){
	return hypot(x[i]-x[j], y[i]-y[j]);
}
int main(){
	ifstream cin("cowtour.in");
	ofstream cout("cowtour.out");
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++){
		cin >> cad;
		for(int j = 0; j < n; j++)
			if(cad[j] == '1')
				dist[i][j] = distancia(i,j);
			else
				dist[i][j]=(i==j ? 0.0 : INF);
	}

	/*Inicio :D :D Floyd Warshal*/
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

	/*Fin Floyd */
	for(int i = 0; i < n; i++){
		may[i] = 0;
		for(int j = 0; j < n; j++)
			if(dist[i][j]<INF && i!=j)
				may[i] = max(may[i],dist[i][j]);
	}

	double sol = INF;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(dist[i][j] >= INF){ // el campo i no esta unido con el campo j por ningun camino
				double tmp = distancia(i,j);
				double di = 0;
				for(int k = 0; k < n; k++){
					if(dist[k][i] < INF) // si hay un camino minimo desde k a i
						di = max(di,max(may[k], dist[k][i]+tmp+may[j]));
					if(dist[k][j] < INF)
						di = max(di,max(may[k], dist[k][j]+tmp+may[i]));
				}
				sol = min(di, sol);
			}
	cout << fixed << setprecision(6) << sol << endl;
	return 0;
}
