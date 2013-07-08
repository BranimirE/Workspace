#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>
#include <iomanip>

using namespace std;
#define MAXN 10000000
int criba[MAXN+1];
void generarCriba(){
	memset(criba,0,sizeof criba);
	for(int i = 2; i <= MAXN; i++ ){
		if(criba[i] == 0){
			for(int j = i; j <= MAXN; j+= i)
				if(criba[j] == 0)
					criba[j] = i;
		}
	}
}
int f(int n){
	for(int i = 2; i <= n; i++)
		if(n%i == 0)
			return i;
	return n;
}
long long int a[MAXN+1];
int tam ;
long long int solve(int n){
	if(n<=tam)
		return a[n];
	for(int i = tam+1; i <= n; i++)
		a[i] = a[i-1] + criba[i];
	tam = n;
	return a[n];
}
int main() {

	generarCriba();

	a[0] = a[1] = 0;
	tam = 1;
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << solve(n)<<endl;
	}

	return 0;
}
