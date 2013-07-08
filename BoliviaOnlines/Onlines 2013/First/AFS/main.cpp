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
#define MAXN 1000000
long long int criba[MAXN+1]={0};
void generarCriba(){
	for(int i = 2; i+i <= MAXN; i++)
		for(int j = i+i; j <= MAXN;j+=i)
			criba[j] += i;
}
long long int a[MAXN+1];
int tam ;
long long int solve(int n){
	if(n<=tam)
		return a[n];
	for(int i = tam+1; i <= n; i++)
		a[i] = a[i-1] + criba[i] + 1;
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
		cout << solve(n) <<endl;
	}
	return 0;
}
