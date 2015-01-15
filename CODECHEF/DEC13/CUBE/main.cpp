#include <cstdio>
#include <cstring>
int min(int a, int b){return (a<b)?a:b;}
#define MAX 64010
using namespace std;
char a[MAX], b[MAX];
int v[45][45][45], f[45][45][45], l[45][45][45], s[45][45][45];
int n, p;
int sup(int i, int x1, int y1, int x2, int y2){
	return s[i][x2][y2] - s[i][x1 - 1][y2] - s[i][x2][y1 - 1] + s[i][x1 - 1][y1 - 1];
}
int lat(int j, int x1, int y1, int x2, int y2){
	return l[x2][j][y2] - l[x1 - 1][j][y2] - l[x2][j][y1 - 1] + l[x1 - 1][j][y1 - 1];
}
int fro(int k, int x1, int y1, int x2, int y2){
	return f[x2][y2][k] - f[x1 - 1][y2][k] - f[x2][y1 - 1][k] + f[x1 - 1][y1 - 1][k];
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &p);
		scanf("%s %s", a, b);
		int pos = 0;
		memset(v, 0, sizeof(v));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++){
					v[i][j][k] = (a[pos] == b[pos]);
					pos++;
				}
		memset(f, 0, sizeof(f));
		memset(l, 0, sizeof(l));
		memset(s, 0, sizeof(s));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++)
					s[i][j][k] = v[i][j][k] + s[i][j - 1][k] + s[i][j][k - 1] - s[i][j - 1][k - 1];
		for(int j = 1; j <= n; j++)
			for(int i = 1; i <= n; i++)
				for(int k = 1; k <= n; k++)
					l[i][j][k] = v[i][j][k] + l[i - 1][j][k] + l[i][j][k - 1] - l[i - 1][j][k - 1];
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					f[i][j][k] = v[i][j][k] + f[i - 1][j][k] + f[i][j - 1][k] - f[i - 1][j - 1][k];
		int ans = -1, cont = 0;

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k =  1; k <= n; k++){
					int mt = min(n - i, min(n - j, n - k)) + 1;
					if(mt < ans) continue;
					int unos = 0;
					for(int tam = 1; tam <= mt; tam++){
						unos += sup(i + tam - 1, j, k, j + tam - 1, k + tam - 1);
						unos += lat(j + tam - 1, i, k, i + tam - 1 - 1, k + tam - 1);
						unos += fro(k + tam - 1, i, j, i + tam - 1 - 1, j + tam - 1 - 1);

						double total = tam * tam * tam;
						double porcentaje  = (unos * 100.0) / total;
						if(porcentaje >= p){
							if(tam > ans){
								ans = tam;
								cont = 1;
							}else if(tam == ans)
								cont++;
						}
					}
				}
		if(ans != -1)
			printf("%d %d\n", ans, cont);
		else
			puts("-1");
	}
	return 0;
}
