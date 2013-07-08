#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>
#define MOD 1000000007
using namespace std;
long long int modpow(long long int a,long long int b,long long int c){
    if(b<=0)return 1;
    long long dev=modpow(a,b/2,c);
    dev=(dev*dev)%c;
    if(b&1)dev=(dev*a)%c;
    return dev;
}

long long int  sol(long long int N){
	if(N<=4)return N;
	long long int b;
	if(N%3 ==1)
		b = modpow(3,(N/3)-1,MOD)*4;
	else if(N%3 == 2)
		b = modpow(3,(N/3),MOD)*2;
	else
		b = modpow(3,(N/3),MOD);
	b = b%MOD;
	return b;
}

int main() {

	int t;
	long long int n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << sol(n)<<endl;
	}
	return 0;
}
