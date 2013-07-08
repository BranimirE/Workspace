/*
ID: brani.e2
PROG: camelot
LANG: C++
*/
// Despues de varios dias en este ejercicio, me rendi asi que busque en los foros de topcoder
// se entiende lo que dice pero no sabia como programarlo
// asi que busque una sol y encontre esta http://usacosolutions.wordpress.com/2012/10/20/usaco-3-3-camelot-camelot-c/ 
// que es muy facil de entender (ojo no hacer copy paste entender la idea y luego programar uno propio)
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXF 41
#define MAXC 27
#define fila first
#define col second

int dy[8] = {-2,-1, 1, 2, 2, 1,-1,-2};
int dx[8] = { 1, 2, 2, 1,-1,-2,-2,-1};

using namespace std;

int filas, cols;
pair<int,int> rey;
int d[MAXF][MAXC][MAXF][MAXC];
vector<pair<int,int> > piezas;
bool esValido(int f, int c){
	return (f>=1 && f <=filas && c>=1 && c <= cols);
}

void BFS(int f, int c){
	queue<pair<int,int> > cola;
	d[f][c][f][c] = 0;
	cola.push(make_pair(f,c));
	while(!cola.empty()){
		pair<int,int> actual = cola.front();
		cola.pop();
		for(int i = 0; i < 8; i++){
			int adyf = actual.fila + dy[i];
			int adyc = actual.col  + dx[i];
			if(esValido(adyf,adyc) && d[f][c][adyf][adyc] == 0x01010101 ){
				d[f][c][adyf][adyc] = d[f][c][actual.fila][actual.col] + 1;
				cola.push(make_pair(adyf,adyc));
			}
		}
	}
}
int reyto(int fila, int col){
	return max(abs(rey.fila-fila),abs(rey.col-col));
}

int main(){
	ifstream cin("camelot.in");
ofstream cout("camelot.out");
	cin >> filas >> cols;
	char c;int f;
	cin >> c >> f;
	rey.fila = f;
	rey.col = c - 'A' + 1;
	while(cin >> c >> f){
		pair<int,int> tmp;
		tmp.fila = f;
		tmp.col = c - 'A' + 1;
		piezas.push_back(tmp);
	}

	memset(d, 1, sizeof (d));
//	for(int i = 1; i <= filas; i++)
//		for(int j = 1; j <= cols; j++)
//			BFS(i,j);

	int sol = INT_MAX;
	//calculamos los limites alrededor del rey debe haber 2 cuadros
	int mp = 2;
	int E = rey.col  + mp>cols?cols:rey.col + mp;
	int O = rey.col  - mp<1?1:rey.col - mp;
	int N = rey.fila - mp<1?1:rey.fila - mp;
	int S = rey.fila + mp>filas?filas:rey.fila + mp;

//No es necesario hacer BFS en todos los i,j's solo en los que se va a utilizar
	for(int i = 0; i < piezas.size(); i++)
		BFS(piezas[i].fila, piezas[i].col);//posiciones de los caballos
	for(int ir = N; ir <= S; ir++)
		for(int jr = O; jr <= E; jr++)
			BFS(ir,jr);		//2 cuadros alrededor del rey

	for(int i = 1; i <= filas; i++)
		for(int j = 1; j <= cols; j++){
			//calculamos el resultado de mover todos los caballos a la pos (i, j)
			int movi = 0;
			for(int k = 0; k < piezas.size();k++)
				movi += d[piezas[k].fila][piezas[k].col][i][j];
			//Ahora recogemos al rey (probamos con el rey moviendose a su alrededor)
			int minimo = reyto(i,j);//minimo numero de movimeintos para recoger al rey e ir al (i,j)
			for(int ir = N; ir <= S; ir++)
				for(int jr = O; jr <= E; jr++){

					for(int k = 0; k < piezas.size(); k++){//probamos si el caballo k puede recoger al rey que se movio a la posicion (ir,jr)
						int tmp = reyto(ir,jr) + d[piezas[k].fila][piezas[k].col][ir][jr] +
							d[ir][jr][i][j] - d[piezas[k].fila][piezas[k].col][i][j];
						minimo = min(minimo, tmp);
					}
					sol = min(sol, movi + minimo);
				}
		}
	cout << sol << endl;
	return 0;
}

