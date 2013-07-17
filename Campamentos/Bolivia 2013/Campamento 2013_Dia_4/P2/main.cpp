#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

#define MAX 50005

#define INF 1<<30

set<pair<int,int > > cola;
int distancia[MAX];
bool visitado[MAX];
vector<pair<int,int> > ady[MAX];

void relajacion( int actual , int adyacente , int peso ){
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso; 
	cola.insert(make_pair(distancia[adyacente], adyacente));
    }
}
void init(){
	for(int i = 0; i < MAX; ++i){
		distancia[i] = INF;
		visitado[i] = false;
	}
}
void dijkstra( int inicial ){
    init(); 
    cola.insert(make_pair(0, inicial));
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !cola.empty() ){                   //Mientras cola no este vacia
	
        actual = (*cola.begin()).second;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
	cola.erase(cola.begin());
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   //id del vertice adyacente
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }
}


int main(){
	freopen("entrada.in", "r", stdin);
	int vertices, caminos, N, a,b,d;
	cin >> vertices >> caminos >> N;
	
	while(caminos--){
		cin >> a >> b >> d;
		ady[a].push_back(make_pair(b, d));
		ady[b].push_back(make_pair(a, d));
	}

	dijkstra( 1 );
	while(N--){
		cin >> a >> b;
		cout << distancia[a] + distancia[b] << endl;
	}
	return 0;
}
