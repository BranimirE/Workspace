/*
ID: brani.e2
PROG: nocows
LANG: C++
 */

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define MOD 9901
#define MAXN 201
#define MAXA 101

int dp[MAXN][MAXA];

int solve (int nodos, int niveles){
	// dp[cnodos][altura] = Sumatoria(dp[k][altura-1]*dp[cnodos-1-k][altura-1]) con k = 1 ... cnodos-2;
	memset(dp,0,sizeof dp);
	for(int altura = 1; altura <= niveles; altura++){
		dp[1][altura] = 1;//caso base
		for(int cnodos = 3; cnodos <= nodos; cnodos += 2){ // no hay arboles con cantidad impar de nodos
			for(int k = 1; k <= cnodos - 2; k++ ){
				dp[cnodos][altura] += dp[k][altura-1]*dp[cnodos-1-k][altura-1];
				dp[cnodos][altura] %= MOD;
			}
		}
	}

	return (dp[nodos][niveles]-dp[nodos][niveles-1]+MOD)%MOD;//le quitamos los arboles de profundiad menor
}

int main() {
	ifstream cin("nocows.in");
	ofstream cout("nocows.out");
	int nodos,niveles;
	cin >> nodos >> niveles;
	if(nodos %2 == 0 )
		cout << 0 << endl;
	else
		cout << solve(nodos,niveles) << endl;
	return 0;
}
