#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>
#define MAXN 1000000
using namespace std;
bool sol[MAXN+1]={false};
long long int fac[20];
int tam;
void generar(){
	tam = 1;
	fac[0] = 1;
	for(int i = 1;; i++){
		fac[i] = fac[i-1]*i;
		if(fac[i]>MAXN)break;
		tam++;
	}
}
void solve(){
	for(int mask = 0; mask < (1<<tam); mask++){
		long long int suma = 0;
		for(int i = 0; i <= tam; i++){
			if(mask&(1<<i)){
				suma += fac[i];
			}
		}
		if(suma <= MAXN)
			sol[suma] = true;
	}
}
int main() {
	generar();
	solve();
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << (sol[n]?"YES":"NO")<<endl;
	}


	return 0;
}
