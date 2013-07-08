/*
ID: brani.e2
PROG: subset
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

long long int contar(int n, int sum){

	long long int subset[sum+1][n+1];
	memset(subset,0,sizeof subset);

	for (int i = 0; i <= n; i++)
		subset[0][i] = 1;

	for (int i = 1; i <= sum; i++)
		subset[i][0] = 0;

	for (int i = 1; i <= sum; i++)//recorremos todas las sumas desde 1 hasta sum
		for (int j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j-1]; // hasta j-1 cuantos subconjuntos que suma i hay
			if (i >= j)
				subset[i][j] += subset[i - j][j-1];
		}
	return subset[sum][n];
}
int main() {
	ifstream cin("subset.in");
	ofstream cout("subset.out");
	int N;
	cin >> N;
	int sum = N*(N+1)/2;
	if(sum % 2 == 0){
		sum /= 2;
		cout << contar(N,sum)/2 << endl;
	}else
		cout << 0 << endl;
	return 0;
}
