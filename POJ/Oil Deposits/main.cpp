#include <iostream>
#include <cstring>

#define MAXN 105
using namespace std;

int filas, cols;
string g[MAXN];
bool v[MAXN][MAXN];
int dx[8] = {0,0,1 ,-1,-1, 1,-1,1};
int dy[8] = {1,-1,0 ,0,-1,-1, 1,1};
void dfs(int i, int j){
	if(!v[i][j]){
		v[i][j] = true;
		for(int k = 0; k < 8; k++){
			int di = i + dx[k];
			int dj = j + dy[k];
			if(g[di][dj] == '@' && !v[di][dj])
				dfs(di,dj);
		}
	}
}
int main(){
	while(cin >> filas >> cols && !(filas == 0 && cols == 0)){
		g[0] = string(MAXN, '*');
		for(int i = 1; i <= filas; i++){
			cin >> g[i];
			g[i] = "*" + g[i] + "*";
		}
		g[filas + 1] = string(MAXN, '*');
		memset(v, false, sizeof v);
		int sol = 0;
		for(int i = 1; i <= filas; i++)
			for(int j = 1; j <= cols; j++)
				if(g[i][j] == '@' && !v[i][j]){
					dfs(i,j);
					sol++;
				}

			
		cout << sol << endl;
	}
	return 0;
}
