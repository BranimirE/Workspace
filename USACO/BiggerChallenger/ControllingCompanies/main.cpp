/*
ID: brani.e2
PROG: concom
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
#define MAXN 100
int t,N,a,b,c;
int grafo[MAXN + 1][MAXN+1];
bool visitado[MAXN+1]={false};
int sum[MAXN+1]={0};

void solve(int ini){
	if(!visitado[ini]){
		visitado[ini] = true;
		for(int i = 0; i <= N; i++){
			sum[i] = sum[i]+grafo[ini][i];
			if(sum[i]>50)
				solve(i);
		}
	}
}
int main() {
	ifstream cin("concom.in");
	ofstream cout("concom.out");
	cin >> t;
	N = 0;
	while(t--){
		cin >> a >> b >> c;
		grafo[a][b] = c;
		N = max(N,max(a,b));
	}
	for(int i = 0; i <= N; i++){
		solve(i);
		for(int j = 0; j <= N; j++){
			if(i!=j && sum[j]>50)
				cout << i << " " << j << endl;
			sum[j] = visitado[j] = 0;
		}
	}
	return 0;
}
