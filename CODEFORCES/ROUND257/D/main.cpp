#include <bits/stdc++.h>
using namespace std;
typedef long long int Number;
const Number MOD = 1000000007LL;
struct matrix{
	Number a, b, c, d;
	matrix(Number A, Number B, Number C, Number D){
		a = A;
		b = B;
		c = C;
		d = D;
	}
	matrix operator *(const matrix &x){
		Number A = ((a * x.a) % MOD + (b * x.c) % MOD + MOD) % MOD;
		Number B = ((a * x.b) % MOD + (b * x.d) % MOD + MOD) % MOD;
		Number C = ((c * x.a) % MOD + (d * x.c) % MOD + MOD) % MOD;
		Number D = ((c * x.b) % MOD + (d * x.d) % MOD + MOD) % MOD;
		return matrix(A, B, C, D);
	}
	matrix pow(Number n){
		if(n == 1)
			return matrix(a, b, c, d);
		matrix ans = pow(n / 2);
		ans = ans * ans;
		if(n & 1LL)
			ans = ans * matrix(a, b, c, d);
		return ans;
	}
};
int main() {
	cout << LLONG_MAX << endl;
	matrix p(0, -1, 1, 1);
	Number a, b, n;
	while(cin >> a >> b >> n){
		if(n == 1){
			cout << (a + MOD) % MOD << endl;
		}else if(n == 2){
			cout << (b + MOD) % MOD << endl;
		}else{
			matrix e = p.pow(n - 1);
			cout << ((b * e.c) % MOD + (a * e.a) % MOD + MOD + MOD)% MOD << endl;
		}
	}
	return 0;
}
