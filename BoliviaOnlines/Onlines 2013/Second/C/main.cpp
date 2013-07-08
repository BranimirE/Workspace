#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define INF 1<<30
#define MAXN 1000000
#define PI acos(-1)
int dx[5]={ 0,1, 0,-1, 0};
int dy[5]={ 0,0, 1, 0,-1};
using namespace std;

int alto, ancho;
bool isValid(int i, int j){
	return (i>=0 && i < alto) && (j>=0 && j < ancho) ;
}

bool solve(int mask, vector<string> v){
	int p = 0;
	for(int i = 0; i < alto; i++)
		for(int j = 0; j < ancho; j++){
			if(mask&(1<<p))
				if(v[i][j] == '.')
					return false;
				for(int k = 0; k < 5; k++){
					int a = i + dx[k], b = j + dy[k];
					if(isValid(a,b) && v[a][b]=='X')
						v[a][b] = 'T';
				}
			p++;
		}
	for(int i = 0; i < alto; i++)
		for(int j = 0; j < ancho; j++)
			if(v[i][j]=='X')
				return false;
	return true;
}
int main(){
	while(cin >> alto>>ancho && !(alto==0 && ancho==0)){
		vector<string> m(alto);
		for(int i = 0; i < alto; i++)
			cin >> m[i];
		int ans = ancho*alto;
		int lim = (1<<(ancho*alto));
		for(int mask = 0; mask<lim; mask++)
			if(solve(mask,vector<string>(m)))
				ans = min(ans, __builtin_popcount(mask));
		cout << ans << endl;
	}
 	return 0;
}
/*
3 4
X...
.X.X
.X..
4 5
....X
.....
XXXXX
X....
2 2
..
.X
2 2
..
..
2 2
XX
XX
0 0


*/
