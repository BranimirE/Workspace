#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

#define PRIMO 1
#define COMPUESTO 0
#define MAXN (1e7)+2
using namespace std;

vector<int> v;
int buscar(int n){
	int izq = 0, der = v.size() - 1;
	// 0 1    
	while(true){
		int m = (izq + der) / 2;
		if(n > v[m] && n > v[m+1]){
			izq = m + 1;
			continue;
		}
		if(n < v[m] && n < v[m-1]){
			der = m - 1;
			continue;
		}
		break;
	}
	return izq;
}
int main(){
	int LIM = sqrt(MAXN) + 1;
	bool criba[LIM];
	criba[0] = criba[1] = COMPUESTO;
	criba[2] = PRIMO;
	for(int i = 4; i < LIM; i += 2)
		criba[i-1] = PRIMO, criba[i] = COMPUESTO;

	for(int i = 3; i * i < LIM; i += 2)
		if(criba[i] == PRIMO)
			for(int j = i + i; j < LIM; j += i)
				criba[j] = COMPUESTO;
	for(int i = 0; i < LIM; i++)
		if(criba[i] == PRIMO)
			for(long long int j = i * i; j < MAXN; j *= i)
				v.push_back(j);
	sort(v.begin(),v.end());
	v.push_back(INT_MAX);
	int t,a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		int i = 0,j;
		while(i < v.size() && a > v[i]) i++;
		j = i;
		while(j < v.size() && b >= v[j]) j++;

		cout << (j-i) << endl;
	}
	return 0;
}
