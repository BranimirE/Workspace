#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 562505
#define Point pair<double,double>
#define x first
#define y second

int padre[ MAX ]; 
int rango[ MAX ];
void MakeSet( int n ){
	for( int i = 1 ; i <= n ; ++i ){
		padre[ i ] = i;
		rango[ i ] = 0;
	}
}
int Find( int x ){
	return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );
}
void Union( int x , int y ){
	int xPadre = Find(x);
	int yPadre = Find(y);
	if(rango[xPadre] > rango[yPadre])
		padre[yPadre] = xPadre;
	else{
		padre[xPadre] = yPadre;
		if(rango[xPadre] = rango[yPadre])
			rango[yPadre]++;
	}
}
bool sameComponent( int x , int y ){
	return  Find( x ) == Find( y );
}

struct Edge{
	int origen;     
	int destino;
	double peso; 
	Edge(){}
	Edge(int o, int d, double p){
		origen = o;
		destino = d;
		peso = p;
	}
	bool operator<( const Edge &e ) const {
		return peso < e.peso;
	}
}arista[ MAX ];    

vector<Point> puntos;

int main(){
	//freopen("entrada.in","r",stdin);
	int N,M, orig, dest;
	double sol;
	Point tmp;
	while(cin >> N){
		puntos.clear();
		puntos.push_back(tmp);//para que empieze desde 1
		for(int i = 0; i < N; ++i){
			cin >> tmp.x >> tmp.y;
			puntos.push_back(tmp);
		}
		cin >> M;
		MakeSet(N);
		while(M--){
			cin >> orig >> dest;
			if(!sameComponent(orig, dest))
				Union(orig, dest);
		}
		M = sol = 0;
		for(int i = 1; i <= N; ++i )
			for(int j = i + 1; j <= N; ++j)
				arista[M++] = Edge(i,j,hypot(abs(puntos[i].x-puntos[j].x), abs(puntos[i].y-puntos[j].y)));
		sort(arista, arista+M);
		for(int i = 0; i < M; ++i)
			if(!sameComponent(arista[i].origen, arista[i].destino)){
				Union(arista[i].origen, arista[i].destino);
				sol += arista[i].peso;
			}
		printf("%.2f\n", sol);

	}
	return 0;
}
