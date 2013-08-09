#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 101

using namespace std;

int vi[MAXN], V[MAXN];
int main(){
	//freopen("entrada.in", "r", stdin);
	int t, n, m, p, cant, tmp;
	unsigned long long int ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(vi, 0, sizeof(vi));
		ans = 0;
		while(m--){
			scanf("%d", &p);
			vi[p]++;
		}
		for(int h = 0; h < n; ++h){
			scanf("%d", &cant);
			for(int i = 0; i < cant; ++i)
				scanf("%d", &V[i]);
			sort(V, V + cant);
			tmp = min(cant, vi[h]);
			for(int i = cant - 1; i >= 0 && tmp; --i, tmp--)
				ans += (long long int)V[i];
		}
		printf("%llu\n", ans);
	}
	return 0;
}
