#include <cstdio>
char c[100];
void solve(int pos,long long ia, long long ib, long long  ma, long long mb, long long da, long long db ){
	if(c[pos])
		if(c[pos] == 'R')
			solve(pos + 1, ma, mb, ma + da, mb + db, da, db );
		else
			solve(pos + 1, ia, ib, ma + ia, mb + ib, ma, mb );
	else
		printf("%lld/%lld\n", ma, mb);
}
int main(){
	int t;
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(c);
		solve(0, 0LL, 1LL, 1LL, 1LL, 1LL, 0LL);
	}
	return 0;
}
