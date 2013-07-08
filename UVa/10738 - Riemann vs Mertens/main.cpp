#include <cstdio>

#define MAX 1000001
using namespace std;

int criba[MAX];
int nfact[MAX];
int mu[MAX],M[MAX];
int main(){
	//freopen("entrada.in","r",stdin);
	
	for(int i = 1; i < MAX; ++i)
		criba[i] = 1, nfact[i] = 0;

	for(int i = 2; i < MAX; ++i )
		if(criba[i] == 1)
			for(int j = i; j < MAX; j += i)
				criba[j] *= i, nfact[j]++;
	mu[1] = 1;
	M[1] = 1;
	for(int i = 2; i < MAX; ++i){
		if(criba[i] == i)
			mu[i] = nfact[i]%2?-1:1;
		else
			mu[i] = 0;
		M[i] = M[i-1] + mu[i];
	}
	int i;
	while(scanf("%d",&i) && i)
		printf("%8d%8d%8d\n", i, mu[i], M[i]);
	return 0;
}
