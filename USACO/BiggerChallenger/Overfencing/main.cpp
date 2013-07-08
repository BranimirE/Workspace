/*
ID: brani.e2
PROG: maze1
LANG: C++
 */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <string.h>
#define MANCHO 40
#define MALTO 110
#define INF 1<<30
using namespace std;
int ancho,alto;
char m[MALTO*2+1+1][MANCHO*2+1+1];
int dist[MALTO*2+1+1][MANCHO*2+1+1];
bool visitado[MALTO*2+1+1][MANCHO*2+1+1];
queue<pair<int,int> > cola;

int bfs(){
	int i ,j;
	int sol = 0;
	memset(visitado,false, sizeof visitado);
	while(!cola.empty()){
		pair<int,int> elem = cola.front();cola.pop();
		i = elem.first;j=elem.second;
		if(visitado[i][j] == false){
			visitado[i][j] = true;

			if(j+2 < ancho  && m[i][j+1] == ' ' && visitado[i][j+2]==false ){//derecha
				cola.push(make_pair(i,j+2));
				if(dist[i][j]+1 < dist[i][j+2]){
					dist[i][j+2] =dist[i][j]+1;
					sol = max(sol, dist[i][j+2]);
				}
			}
			if(j-2 >=  0 && m[i][j-1] == ' ' && visitado[i][j-2]==false){//izquierda
				cola.push(make_pair(i,j-2));
				if(dist[i][j]+1 < dist[i][j-2]){
					dist[i][j-2] =dist[i][j]+1;
					sol = max(sol,dist[i][j-2]);
				}
			}
			if(i-2 >= 0  && m[i-1][j] == ' ' && visitado[i-2][j]==false){//arriba
				cola.push(make_pair(i-2,j));
				if(dist[i][j]+1 < dist[i-2][j]){
					dist[i-2][j] =dist[i][j]+1;
					sol = max(sol, dist[i-2][j]);
				}
			}
			if(i+2< alto && m[i+1][j] == ' ' && visitado[i+2][j]==false){//abajo
				cola.push(make_pair(i+2,j));
				if(dist[i][j]+1 < dist[i+2][j]){
					dist[i+2][j] =dist[i][j]+1;
					sol = max(sol, dist[i+2][j]);
				}
			}
		}

	}
	return sol;
}
int main() {
	ifstream cin("maze1.in");
	ofstream cout("maze1.out");
	cin >> ancho >> alto;
	cin.getline(m[0],100);
	for(int i = 0; i < alto*2+1; i++)
		cin.getline(m[i],ancho*2+3);
	ancho = ancho*2+1;
	alto = alto*2+1;
	for(int i = 0; i < alto;i++)
		for(int j = 0; j < ancho;j++)
			dist[i][j] = INF;

	for(int i = 0; i < ancho; i++){
		if(m[0][i]==' '){//arriba
			cola.push(make_pair(1,i));
			dist[1][i] = 0;
		}
		if(m[alto-1][i]==' '){//abajo
			cola.push(make_pair(alto-2,i));
			dist[alto-2][i] = 0;
		}
	}


	for(int i = 0; i < alto; i++){
		if(m[i][0]==' '){
			cola.push(make_pair(i,1));
			dist[i][1] = 0;
		}
		if(m[i][ancho-1]==' '){
			cola.push(make_pair(i,ancho-2));
			dist[i][ancho-2] = 0;
		}
	}

	cout << bfs()+1 << endl;
	return 0;
}
