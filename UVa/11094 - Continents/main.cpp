#include <iostream>
#include <fstream>

#define MAXN 30

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};


int filas, cols, fi, co;
string c[MAXN];
char isla = 0;
int cont = 0;
void dfs(int i, int j){
	c[i][j] = 0;
	cont++;
	for(int k = 0; k < 4; ++k){
		int x = (i + dx[k]);
		int y = (j + dy[k] + cols) % cols;
		if(x>=0 && x < filas && c[x][y] == isla)
			dfs(x,y);
	}
}
int main(){
	while(cin >> filas >> cols){
		for(int i = 0; i < filas; ++i)		
			cin >> c[i];
		cin >> fi >> co;
		isla = c[fi][co];
		dfs(fi,co);
		int ans = 0;
		for(int i = 0; i < filas; ++i)
			for(int j = 0; j < cols; ++j)
				if(c[i][j] == isla){
					cont = 0;
					dfs(i,j);
					ans = max(ans,cont);
				}
		cout << ans << endl;
	}
	return 0;
}
