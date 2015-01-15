#include <cstdio>
#define MAXN 13
using namespace std;
long long int f[MAXN];
int main(){
	f[0] = 1;
	for(long long int i = 1; i < MAXN; i++)
		f[i] = i * f[i-1];
	f[0] = 0;
	int t,a;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		printf("%lld\n", f[a-1]);
	}
	return 0;
}
