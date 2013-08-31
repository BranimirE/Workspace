#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int nrosol, f, c;
int sol[10];
bool sePuede(int fila, int col){
	if(col != c &&fila == f)return false;
	for(int i = col - 1 ; i >= 1; i--)
		if(sol[i] == fila || (abs(sol[i] - fila) == abs(i - col)))
			return false;
	return true;
}
void solve(int col){
	if(col == 9){
		if(sol[c] == f){
			printf("%2d      %d", nrosol++, sol[1]);
			for(int i = 2; i <= 8; i++)
				printf(" %d", sol[i]);
			printf("\n");
		}
		return ;
	}
	for(int i = 1; i <= 8; i++)
		if(sePuede(i, col)){
			sol[col] = i;
			solve(col + 1);
		}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		printf( "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n" );
		cin >> f >> c;
		scanf("%d %d", &f, &c);
		nrosol = 1;
		memset(sol, 0, sizeof(sol));
		sol[c] = f;
		solve(1);
		if(T)
			puts("");
	}
	return 0;
}
