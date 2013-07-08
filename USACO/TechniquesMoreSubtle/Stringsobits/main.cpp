/*
ID: brani.e2
PROG: kimbits
LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;
#define MAXN 31
long long int dp[MAXN+1][MAXN+1];
void solve(){
	for(int i = 0; i <= MAXN; i++)
		dp[i][0] = dp[i][i] = 1;
	for(int i = 1; i <= MAXN; i++)
		for(int j = 1; j <= i; j++)
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
	for(int i = 1; i <= MAXN; i++)
		for(int j = 1; j <= MAXN; j++)
			dp[i][j] += dp[i][j-1];
}
int main() {
	//ifstream cin("kimbits.in");
	//ofstream cout("kimbits.out");
	solve();
	int bits,tam;
	long long int N;
	while(cin >> tam >> bits >> N){
		string sol(tam,'0');
		//dp[tam][bits] me dice cuantos numeros hay de tamañano tam y con 1 a bits o menos encendidos
		for(int i = 0; i < tam; i++){
			//vemos si ...XBBBB.. el bit X puede ser 1 , BBBB bits para llenar
			if(N > dp[tam-i-1][bits] ){ /* es 1 si uso todos los bits que tengo disponibles
									  para llenar y aun asi no alcanza al numero que pide*/
				sol[i] = '1';
				N -= dp[tam-i-1][bits];
				bits--;
			}else if(tam-i-1 == bits) // si tengo mas bits disponibles para llenar que los espacios que
				bits--;				// me quedan por llenar elimino bits para llenar
		}
		cout << sol << endl;
	}
	return 0;
}
/*
for(int i = 1; i <= pow(2,5);i++)
	if(__builtin_popcount(i)<=3){
		cout << (bitset<5>(i))<<" -> "<<i<<endl;
	}*/
