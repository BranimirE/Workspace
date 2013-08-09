#include <cstdio>
#include <iostream>

using namespace std;

int main(){
//	freopen("entrada.in", "r", stdin);

	int casos;
	long long int n,k;
	scanf("%d", &casos);
	while(casos--){
		scanf("%lld%lld", &n, &k);
		if(k)
			printf("%lld %lld\n", n/k, n%k);
		else
			printf("%lld %lld\n", k, n);
	}

	return 0;
}
