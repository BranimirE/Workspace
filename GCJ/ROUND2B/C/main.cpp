#include <bits/stdc++.h>
#define MAXANCHO 105
#define MAXALTO 500
using namespace std;
int ancho, alto, edif;
bool v[MAXALTO][MAXANCHO];
vector<int> g[MAXANCHO * MAXALTO * 2];
int identra[MAXANCHO * MAXALTO * 2];
int idsale[MAXANCHO * MAXALTO * 2];
int main() {
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> ancho >> alto >> edif;
		memset(v, false, sizeof(v));
		while(edif--){
			int i1, i2, j1, j2;
			cin >> j1 >> i1 >> j2 >> i2;
			for(int i = i1; i <= i2; i++)
				for(int j = j1; j <= j2; j++)
					v[i][j] = true;
		}
		int id = 1
		for(int i = 0; i < alto; i++, cout << endl)
			for(int j = 0; j < ancho; j++)

	}

	return 0;
}

