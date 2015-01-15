#include <vector>
#include <bitset>
#include <cstdio>
#include <cmath>

#define MAXPRIME 10005 

using namespace std;

bitset<MAXPRIME> criba;
vector<long long int> primos;
vector<long long int> f;
void llena_criba()
{
	criba.set();
	for (int i = 2; i < MAXPRIME; i++)
		if (criba.test( i ))
		{
			primos.push_back( i );
			for (int j= i + i; j<MAXPRIME; j += i)
				criba.reset( j );
		}
}
void factorizar(long long int n){
	f.clear();
	int i = 0;
	while(i < primos.size() && primos[i]*primos[i] <= n){
		while(n%primos[i] == 0){
			f.push_back(primos[i]);
			n /= primos[i];
		}
		i++;
	}
	if(n > 1){
		f.push_back(n);
	}
}
int main(){
	llena_criba();
	int t;
	long long int n;
	scanf("%d", &t);
	while(t--){	
		scanf("%lld", &n);
		factorizar(n);
		for(int i = 0; i < f.size(); i++){
			if(i)printf(" * ");
			printf("%lld", f[i]);
		}
		puts("");
	}
	return 0;
}
