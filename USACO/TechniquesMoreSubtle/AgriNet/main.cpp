/*
ID: brani.e2
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;
#define MAXN 105
#define INF 1<<30

int N;
int grafo[MAXN][MAXN];

int distancia[MAXN]; // es la distancia del arbol al nodo J que no esta en el arbol
int source[MAXN];// es el id del nodo que esta en el arbol y que esta mas cerca
// del nodo J que esta fuera del arbol
bool enelarbol[MAXN];
int costoarbol, tamarbol;

int prim(){
	for(int i = 1; i <= N; i++){
		distancia[i] = INF;  // Ninguno esta conectado
		enelarbol[i] = false; // Ninguno esta en el arbol
		source[i] = -1; // el nodo i fuera del arbol no esta cerca de ninguno
	}
	/*Añadimos el primer nodo al arbol MST*/
	tamarbol = 1;
	costoarbol = 0;
	enelarbol[1] = true;
	/*Actualizamos las distancias para todos los vecinos del nodo 1*/
	for(int j = 1; j <= N; j++)
		if(grafo[1][j] != 0){
			distancia[j] = grafo[1][j];
			source[j] = 1;
		}


	while(tamarbol < N){
		int i = -1;
		/*Encontramos el nodo con distancia minima al arbol*/
		for(int j = 1; j <= N; j++)
			if(enelarbol[j] == false)
				if(i == -1)
					i = j;
				else
					if(distancia[j] < distancia[i])
						i = j;
		if(i == -1){//NO se encontro alguna conexion al arbol
			//posiblemente el grafo no es conectado
			return -1;
		}

		/*Adicionamos el nodo al arbol*/
		tamarbol++;
		costoarbol += distancia[i];
		enelarbol[i] = true;

		/*Actualizamos las distancias del nodo I a los otros nodos fuera del arbol*/
		for(int j = 1; j <= N; j++ )
			if(grafo[i][j] < distancia[j]){ //con el nuevo nodo podria ser mas corta la distancia al arbol
				distancia[j] = grafo[i][j];
				source[j] = i;
			}
	}

	return costoarbol;
}
int main() {
	ifstream cin("agrinet.in");
	ofstream cout("agrinet.out");
	cin >> N;
	for(int i = 1 ; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> grafo[i][j];
	cout << prim() << endl;
	return 0;
}

