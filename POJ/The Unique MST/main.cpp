/**********************************************
 ***Algoritmo: Minimum Spanning Tree - Kruskal
 ***Tipo: Teoria de Grafos
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************/
/*
EJEMPLO DE INPUT
9 14
1 2 4
1 8 9
2 3 9
2 8 11
3 4 7
3 9 2
3 6 4
4 5 10
4 6 15
5 6 11
6 7 2
7 8 1
7 9 6
8 9 7
*/
/*
EJEMPLO VERIFICACION DE MST
9 11
1 2 4
1 8 9
2 3 9
2 8 11
3 9 2
7 8 1
7 9 6
8 9 7

4 5 10
4 6 15
5 6 11
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>


#define MAX 10005  //maximo numero de vértices
using namespace std;
int padre[ MAX ]; //Este arreglo contiene el padre del i-esimo nodo

//Método de inicialización
void MakeSet( int n ){
    for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;
}

//Método para encontrar la raiz del vértice actual X
int Find( int x ){
    return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );
}

//Método para unir 2 componentes conexas
void Union( int x , int y ){
    padre[ Find( x ) ] = Find( y );
}

//Método que me determina si 2 vértices estan o no en la misma componente conexa
bool sameComponent( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;
    return false;
}
///FIN UNION-FIND

int V , E;      //numero de vertices y aristas
//Estructura arista( edge )
struct Edge{
    int origen;     //Vértice origen
    int destino;    //Vértice destino
    long long int peso;       //Peso entre el vértice origen y destino
    Edge(){}
    //Comparador por peso, me servira al momento de ordenar lo realizara en orden ascendente
    //Cambiar signo a > para obtener el arbol de expansion maxima
    bool operator<( const Edge &e ) const {
        return peso < e.peso;
    }
}arista[ MAX ];      //Arreglo de aristas para el uso en kruskal
Edge MST[ MAX ];     //Arreglo de aristas del MST encontrado

long long int Kruskal(){
    int origen , destino , peso;
    long long int total = 0;          //Peso total del MST
    int numAristas = 0;     //Numero de Aristas del MST

    MakeSet( V );           //Inicializamos cada componente
    std::sort( arista , arista + E );    //Ordenamos las aristas por su comparador

    for( int i = 0 ; i < E ; ++i ){     //Recorremos las aristas ya ordenadas por peso
        origen = arista[ i ].origen;    //Vértice origen de la arista actual
        destino = arista[ i ].destino;  //Vértice destino de la arista actual
        peso = arista[ i ].peso;        //Peso de la arista actual

        if( !sameComponent( origen , destino ) ){  //Evito ciclos
            total += peso;              //Incremento el peso total del MST
            MST[ numAristas++ ] = arista[ i ];  //Agrego al MST la arista actual
            Union( origen , destino );  //Union de ambas componentes en una sola
        }
    }

    if( V - 1 != numAristas ){
        return -1;
    }

    return total;
}

int main(){
	int t;
	cin >> t;
	while(t--){


		int mst;

		scanf("%d %d" , &V , &E );

		for( int i = 0 ; i < E ; ++i ){
			scanf("%d %d %d" , &arista[ i ].origen , &arista[ i ].destino , &arista[ i ].peso );
			arista[i].origen--;
			arista[i].destino--;
		}

		long long int k = Kruskal();
		if(k == -1)
			cout << "Not Unique!" << endl;
		else
			cout << k << endl;
	}
	return 0;
}
