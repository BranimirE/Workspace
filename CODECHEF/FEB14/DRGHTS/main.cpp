#include <cstdio>
#include <vector>
#include <cstring>

#define MAX 50005
typedef long long int Number;
using namespace std;

int n, m, tmp;
bool o[MAX];
bool v[MAX];
vector<int> g[MAX];
Number wind;
bool end[MAX]; //end in open window
bool dfs(int u){
	v[u] = true;
	wind += o[u];
	bool ans = o[u];
	for(int i = 0; i < g[u].size(); i++)
		if(!v[g[u][i]])
			ans |= dfs(g[u][i]);
	return end[u] = ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &tmp);
		o[i] = (tmp == 1);
	}
	while(m--){
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);g[b].push_back(a);
	}
	memset(v, false, sizeof(v));
	memset(end, false, sizeof(end));
	Number pairs = 0, p = 0;
	for(int i = 1; i <= n; i++)
		if(!v[i] && o[i]){
			wind = 1;
			v[i] = true;
			for(int j = 0; j < g[i].size(); j++)
				end[i] |= dfs(g[i][j]);
			pairs += (wind * (wind - 1) / 2LL);
		}

	for(int i = 1; i <= n; i++)
		p += end[i];

	printf("%lld %lld\n", pairs, p);
	return 0;
}
