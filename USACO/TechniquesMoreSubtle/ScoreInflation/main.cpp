/*
ID: brani.e2
PROG: inflate
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 10001

int n,tdisp,tiempo,puntos, dp[MAXN]={0}; // guardara el puntaje maximo obtenible con i minutos hasta el momento

int main() {
	ifstream cin("inflate.in");
	ofstream cout("inflate.out");
	cin >> tdisp >> n;
	while(n--){
		cin >> puntos >> tiempo;
		for(int i = tiempo; i <= tdisp; i++)
			dp[i] = max(dp[i], dp[i-tiempo]+puntos);
	}
	cout << dp[tdisp] << endl;
	return 0;
}
/*
35 20
100 60
120 100
250 120

 */
