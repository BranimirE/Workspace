/*
ID: brani.e2
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
	ifstream cin("fence9.in");
	ofstream cout("fence9.out");
	double n, m, p, x1, x2;
	long long int sol = 0;
	cin >> n >> m >> p;

	for(double y = 1; y < m; ++y){
		x1 = (n*y/m);
		if((int)x1 == x1) x1++;
		else x1 = ceil(x1);

		x2 = ((n-p)*y/m + p);
		if((int)x2 == x2) x2--;
		else x2 = floor(x2);

		sol += (x2 - x1) + 1;
	}
	cout << sol << endl;
	return 0;
}
