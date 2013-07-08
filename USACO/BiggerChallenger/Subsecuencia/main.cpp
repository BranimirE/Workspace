#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define SIZE 200000
#define MAXN 200000

using namespace std;

int best[SIZE];
int val[SIZE];
int n,i,j,sol, tambest;
void funcion();
int main() {

	//lectura
	cin >> n;
	for (i = 0; i < n; i++)	cin >> val[i];
	//proceso
	sol = 0;

	for(i = n-1; i >= 0; i--){
		if(val[i]<best[0]){
			best[0] = val[i]; break;}

		for(j = sol -1; j >= 0 && val[i] <= best[j];j--);
		best[j+1] = val[i];
		sol = max(sol, j+2);
	}
	cout << "la sol es: " << sol << endl;

	return 0;
}
void funcion(){
	long num[MAXN], bestrun[MAXN];
	long n, i, j, highestrun = 0;
	cin >> n;
	for (i = 0; i < n; i++) cin >>num[i];
	bestrun[0] = num[n-1];
	highestrun = 1;
	for (i = n-1-1; i >= 0; i--)
		for (j = highestrun - 1; j >= 0; j--)
			if (num[i] > bestrun[j])
				if (j == highestrun - 1 || num[i] < bestrun[j+1]){
					bestrun[++j] = num[i];
					if (j == highestrun)
						highestrun++;
					break;
				}
	printf("best is %d\n", highestrun);
}
/*
-------------------------------------------
5
5 4 3 2 1

5
5 0 3 2 1

10
4 3 2 1 8 1 7 0 6 5

-------------------------------------------
 */
