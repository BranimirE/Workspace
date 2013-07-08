/*
ID: brani.e2
PROG: game1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>
#define MAXN 101

using namespace std;

int n;
int v[MAXN];
int memo[MAXN][MAXN][2];
int solve( bool turno, int i, int j ){
	if(memo[i][j][turno] != -1)
		return memo[i][j][turno];
	if(i == j){
		if(turno)
			return v[i];
		else
			return 0;
	}
	int op1 = (turno?v[i]:0) + solve(!turno, i + 1, j    );
	int op2 = (turno?v[j]:0) + solve(!turno, i    , j - 1);

	int sol = turno?max(op1, op2):min(op1,op2);
	memo[i][j][turno] = sol;
	return sol;
}
int main(){
	ifstream cin("game1.in");
//	ofstream cout("game1.out");
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		sum += v[i];
	}
	memset(memo, -1, sizeof memo);
	int sol = solve(true,0, n - 1);
	cout << sol << " " << sum-sol << endl;
	return 0;
}
