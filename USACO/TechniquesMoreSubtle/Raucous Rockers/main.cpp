/*
ID: brani.e2
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int n,t,m;
int v[21];

int main(){
	ifstream cin("rockers.in");
	ofstream cout("rockers.out");
	cin >> n >> t >> m;
	for(int i = 0; i < n; ++i) cin >> v[i];

	int sol = 0;
	for(int mask = 0; mask < (1<<n); ++mask){
		int disco = 1;
		int lda = t; // espacio libre en el disco actual
		int cg = 0; // canciones grabadas
		for(int i = 0; i < n && disco <= m; ++i)
			if(mask & (1<<i))
				if(lda >= v[i]){
					lda -= v[i];
					cg++;
				}
				else{
					disco++;
					lda = t;
					i--;
				}
		sol = max(sol,cg);
	}
	cout<< sol << endl;
	return 0;
}


