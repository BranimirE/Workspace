#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
const Number MOD = 1000000007LL;
long long fibonacci(Number n, Number a, Number b){
	Number fib[2][2]= {{1,1},{1,0}}, ret[2][2] = {{1, 0},{0, 1}},tmp[2][2] = {{0,0},{0,0}};
	int i, j, k;
	while(n) {
		if(n & 1LL) {
			memset(tmp,0,sizeof tmp);
			for(i = 0; i < 2; i++)
				for(j = 0; j < 2; j++)
					for(k = 0; k < 2; k++)
						tmp[i][j] = (tmp[i][j] + ((ret[i][k] * fib[k][j]) % MOD)) % MOD;
			for(i = 0; i < 2; i++)
				for(j = 0; j < 2; j++)
					ret[i][j] = tmp[i][j];
		}
		memset(tmp,0,sizeof tmp);
		for(i = 0; i < 2; i++)
			for(j = 0; j < 2; j++)
				for(k = 0; k < 2; k++)
					tmp[i][j] = (tmp[i][j] + fib[i][k] * fib[k][j]);
		for(i = 0; i < 2; i++)
			for(j = 0; j < 2; j++)
				fib[i][j] = tmp[i][j];
		n /= 2LL;
	}

	return (ret[0][1]);
}
int main() {
	Number a, b, n;
	while(cin >> a >> b >> n)
		cout << fibonacci(n, a, b) << endl;
	return 0;
}
