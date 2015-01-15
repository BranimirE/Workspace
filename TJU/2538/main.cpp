#include <cstdio>

using namespace std;

long long int sum[302];

int main(){
	sum[0] = 0;
	for(int i = 1; i <= 300; i++ )
		sum[i] = sum[i-1] + (i*(i+1)*(i+2) / 2);
	int t, n;
	scanf("%d", &t);
	for(int caso = 1; caso <= t; caso++){
		scanf("%d", &n);
		printf("%d %d %lld\n",caso, n, sum[n]);
	}
	return 0;
}
