
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>


using namespace std;

#define MAX 6010


int padre[ MAX ];

void MakeSet( int n ){for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;}
int Find( int x ){return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );}
void Union( int x , int y ){padre[ Find( x ) ] = Find( y );}
bool sameComponent( int x , int y ){return  Find( x ) == Find( y );}

int V , E;      //numero de vertices y aristas
struct Edge{
	int origen;
	int destino;
	int peso;
	Edge(){}
	bool operator<( const Edge &e ) const {
		return peso < e.peso;
	}
}arista[ MAX ];
Edge MST[ MAX ];
long long int Kruskal(){
	int origen , destino , peso;
	long long int total = 0;
	int numAristas = 0;

	MakeSet( V +1 );
	sort( arista , arista + E );

	for( int i = 0 ; i < E ; ++i ){
		origen = arista[ i ].origen;
		destino = arista[ i ].destino;
		peso = arista[ i ].peso;

		if( !sameComponent( origen , destino ) ){
			total += peso;
			numAristas++;
			Union( origen , destino );
		}
	}
	if( V - 1 != numAristas ){
		//cout << ("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.")<<endl;
		return 0;
	}
	return total ;
}

int main(){
	//freopen("entrada.in","r",stdin);
	int casos;
	cin >> casos;
	while(casos--){
		while(cin >> V >> E && !(V==0 && E == 0)){
			long long int tot = 0;
			for( int i = 0 ; i < E ; ++i ){
				cin >> arista[i].origen >> arista[i].destino>> arista[i].peso;
				arista[i].origen++;
				arista[i].destino++;
			}
			cout << Kruskal() << endl;

		}
	}
	return 0;
}

/*
2
3 3
0 1 5
0 2 5
1 2 10
5 7
3 4 187
0 3 192
1 4 172
3 2 163
2 1 157
3 4 169
2 0 177

*/
