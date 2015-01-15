#include <cstdio>
using namespace std;
int n, p, t;
void solve(){
	scanf("%d%d", &n, &p);
	p += 2 * n;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++){
			printf("%d %d\n", i, j);
			p--;
			if(!p)return;
		}
}
int main(){
	scanf("%d", &t);
	while(t--)solve();
	return 0;
}
