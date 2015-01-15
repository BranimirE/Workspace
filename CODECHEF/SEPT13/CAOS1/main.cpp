#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 55
#define INF 1<<29
using namespace std;

int fil, col;
char g[MAX][MAX];
int dx[4] = {-1,0,1, 0};//para las filas
int dy[4] = { 0,1,0,-1};//para las columnas
//            N,E,S,O

int L[MAX][MAX], R[MAX][MAX], T[MAX][MAX],B[MAX][MAX] ;
int main(){
	int t;	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &fil, &col);
		getchar();
		for(int i = 1; i <= fil; i++){
			g[i][0] = '#';
			gets(g[i] + 1);
			g[i][col+1] = '#';
			g[i][col+2] = '\0';
		}
		for(int i = 0; i <= fil + 1; i++)
			for(int j = 0; j <= col + 1; j++)
				R[i][j] = L[i][j] = T[i][j] = B[i][j] = INF;
		for(int i = 1; i <= fil; i++){
			for(int j = 1; j <= col; j++){
				if(g[i][j] == '^'){
					int k;
					if(R[i][j] == INF ){
						k = j;
						while(g[i][k + 1] == '^') 
							k++;
						for(int r = j; r <= k; r++){
							R[i][r] = k - r;
							L[i][r] = r - j;
						}
					}

					if(T[i][j] == INF){
						k = i;
						while(g[k + 1][j] == '^')
							k++;
						for(int r = i; r <= k; r++){
							B[r][j] = k - r;
							T[r][j] = r - i;
						}
					}

				}
			}
		}
		/*for(int i = 1; i <= fil; i++){
			for(int j = 1; j <= col; j++)
				if(g[i][j] == '^')
					printf("(%d,%d,%d,%d) ", T[i][j], R[i][j], B[i][j], L[i][j]);
				else
					printf("    X     " );
			puts("");
		}
		puts("");
		*/
		int ans = 0;
		for(int i = 1; i <= fil; i++)
			for(int j = 1; j <= col; j++)
				if(g[i][j] == '^'){
					int tmp = min(min(R[i][j],L[i][j]), min(T[i][j], B[i][j]));
					if(tmp >= 2)
						ans++;
				}
		printf("%d\n", ans);
	}
	return 0;

}
