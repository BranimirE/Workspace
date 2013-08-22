#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
bool v[10];
bool valid(int n){
	if( int(log10(n)) + 1 > 5)return false;
	int nrodig = 5;
	while(nrodig--){
		int dig = n%10;
		if(v[dig])return false;
		v[dig] = true;
		n /= 10;
	}
	return true;
}
int main(){
	int N;
	int ini = 1234;
	int fin = 98765;
	bool blankline = false;
	while(cin >> N && N){
		if(blankline)cout << endl;
		blankline = true;
		bool sw = true;
		for(int den = ini; den <= fin; ++den){
			memset(v, false, sizeof(v));
			if(valid(den) && valid(den * N)){
				printf("%05d / %05d = %d\n", den * N, den, N);
				sw = false;
			}
		}
		if(sw)
			cout << "There are no solutions for "<< N << "." << endl;
	}
	return 0;
}
