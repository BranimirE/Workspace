/*
ID: brani.e2
PROG: fact4
LANG: C
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define MAXN 4220
int N;
int lp[MAXN+1]={0};
int fact[MAXN+1] = {0};
vector<int> pr;
void generarPrimos(){
	for (int i=2; i<=N; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; j++)
			lp[i * pr[j]] = pr[j];
	}
}
void factorizar(int n ){
	for(int i = 0; i < pr.size() && pr[i]*pr[i]<=n ; i++)
		while(n%pr[i]==0){
			fact[pr[i]]++;
			n /= pr[i];
		}
	if(n>1)
		fact[n]++;
}
int modpow(int b, int e,int mod){
	if(e == 0)
		return 1;
	long long int tmp =  modpow(b, e/2, mod)%mod;
	return (tmp*tmp*((e%2==0)?1:b%mod))%mod;
}
int main() {
	ifstream cin("fact4.in");
	ofstream cout("fact4.out");
	cin >> N;
	generarPrimos();
	for(int i = 1; i <= N; i++)
		factorizar(i);
	int tmp = min(fact[2],fact[5]);
	fact[2] -= tmp;	fact[5] -= tmp;
	int sol = 1;
	for(int i = 0; i < (int)pr.size() && pr[i]<=N; i++)
		sol = (sol*modpow(pr[i],fact[pr[i]],10))%10;
	cout << sol << endl;
	return 0;
}
/*
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
9! = 362880
10! = 3628800
11! = 39916800
12! = 479001600
13! = 6227020800
14! = 87178291200
15! = 1307674368000
16! = 20922789888000
17! = 355687428096000
18! = 6402373705728000
19! = 121645100408832000
20! = 2432902008176640000
 */
