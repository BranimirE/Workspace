#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
int n, m;
string g[123];
bool vis[123][123];
int dx[8] = {-1, 1, 0, 1,-1, 1, 0,-1};
int dy[8] = {-1, 0, 1,-1, 1, 1,-1, 0};
int cont[10];
void dfs(int i, int j, char val){
	vis[i][j] = true;
	for(int k = 0; k < 8; k++){
		int ii = i + dx[k];
		int jj = j + dy[k];
		if(vis[ii][jj] == false && g[ii][jj] == val){
			assert(ii >= 0 && ii <= (n + 1) && jj >= 0 && jj <= (m + 1));
			dfs(ii, jj, val);
		}
	}
}
int main(){
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n >> m;
		g[0] = g[n + 1] = string(m + 2, '0');
		for(int i = 1; i <= n; i++){
			cin >> g[i];
			g[i] = "0" + g[i] + "0";

		}
		/*cout << n << " " << m << endl;
		for(int i = 0; i <= n + 1; i++)
			cout << g[i] << endl;
		 */
		memset(vis, false, sizeof(vis));
		memset(cont, 0, sizeof(cont));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				if(vis[i][j] == false && g[i][j] != '0'){
					cont[g[i][j] - '0']++;

					dfs(i, j, g[i][j]);

				}
			}
		printf("Caso #%d: %d\n", caso, accumulate(cont + 1, cont + 10, 0));
		for(int i = 1; i <= 9; i++){
			if(i != 1)
				cout << " ";
			cout << cont[i];
		}
		cout << endl;

	}

	return 0;
}
