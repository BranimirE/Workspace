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
#define MAXN 105
#define PI acos(-1)
#define IZQ 0
#define DER 1
using namespace std;
string g[MAXN];

int casos,n;
int buscarX(string c){
	for(int i = 0; i < c.size(); i++)
		if(c[i] == 'X')return i;
	return -1;
}
int main(){
	cin >> casos;
	while(casos--){
		cin >> n;
		int A = 0, B = 0;
		int ux = -1;
		for(int i = 0; i < n; i++){
			cin >> g[i];
			if(ux == -1)
				ux =  buscarX(g[i]);
		}

		for(int i = 0; i < n; i++){
			int bx = buscarX(g[i]);
			if( bx == -1)
				if(ux == 0) B += 3;
				else A += 3;
			else{
				A += bx;
				B += (3-bx-1);
				ux = bx;
			}
		}
		cout << A << " " << B << endl;

	}
	return 0;
}
/*
3
3
.X.
.X.
.X.
3
...
X..
.X.
8
...
X..
.X.
..X
...
..X
.X.
X..

 */
