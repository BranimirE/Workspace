#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;
#define MAXN 21
int n;
long long int suma;
long long int vec[MAXN];
int main() {
	cin >> n >> suma;
	for(int i = 0; i < n; i++)
		cin >> vec[i];
	for(int mask = 0; mask < (1<<n); mask++){
		long long int sumatmp = 0;
		for(int i = 0; i < n; i++)
			if(mask&(1<<i))
				sumatmp += vec[i];

		if(sumatmp == suma){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
