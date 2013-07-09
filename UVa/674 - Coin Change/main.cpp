#include <cstdio>

using namespace std;

int v[5] = {50, 25, 10, 5 , 1};
int dp[7490], obj = 7490, i, j;
char b[20], *ptr;

int main(){
	freopen("entrada.in", "r", stdin);
	dp[0] = 1;
	for(i = 0; i < 5; i++)
		for(j = v[i]; j < obj; j++)
			dp[j] += (dp[j-v[i]]);
	while(gets(b)){
		obj = 0;
		for(ptr = b; *ptr; ptr++)obj = obj * 10 + ((*ptr)-'0');
		printf("%d\n", dp[obj]);
	}
	return 0;
}
