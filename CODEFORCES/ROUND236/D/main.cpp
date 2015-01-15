#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 32000
typedef long long int Number;
vector<Number> primes;
vector<Number> badprimes;
void generate_primes(){
	bool v[MAXN];
	fill(v, v + MAXN, false);
	for(int i = 2; i * i < MAXN; i++)
		if(!v[i])
			for(int j = i + i; j < MAXN; j += i)
				v[j] = true;
	for(int i = 2; i < MAXN; i++)
		if(!v[i])
			primes.push_back(i);
}

vector<pair<Number, int> > factorize(Number n){
	vector<pair<Number,int> > ans;
	int pos = 0;
	while(primes[pos] * primes[pos] <= n){
		if(n % primes[pos] == 0){
			int c = 0;
			while(n % primes[pos] == 0){
				n /= primes[pos];
				c++;
			}
			ans.push_back(make_pair(primes[pos], c));
		}
		pos++;
	}
	if(n > 1)ans.push_back(make_pair(n, 1));
	return ans;
}
Number f(Number n){
	vector<pair<Number, int> > factors = factorize(n);
	Number factor, cont, ans = 0;
	for(int i = 0; i < factors.size(); i++){
		factor = factors[i].first;
		cont = factors[i].second;
		if(binary_search(badprimes.begin(), badprimes.end(), factor))
			ans -= cont;
		else
			ans += cont;
	}
	return ans;
}
int n, m;
Number a[5005];

int funcion(int n){
	for(int i = 2; i <= n; i++)
		if(n % i == 0){
			if(binary_search(badprimes.begin(), badprimes.end(), i))
				return -1 + funcion(n / i);
			else
				return 1 + funcion(n / i);
		}
	return 0;
}

int main() {
	generate_primes();
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
	badprimes.assign(m,0);
	for(int i = 0; i < m; i++)scanf("%lld", &badprimes[i]);
	sort(badprimes.begin(), badprimes.end());
	Number ff[n + 1];
	ff[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		ff[i] = ff[i + 1] + f(a[i]);
		//cout << " " << i << " : " << ff[i] << endl;
	}
	Number gcd = a[0], normal = f(a[0]),best = max(normal, normal - f(gcd) ) + ff[1];

	cout << "best :" << best << endl;
	cout << "f1 : " << ff[1] << endl;
	for(int i = 1; i < n; i++){
		gcd = __gcd(gcd, a[i]);
		normal += f(a[i]);
		best = max(best, max(normal, normal - (f(gcd) * (i + 1))) + ff[i + 1]) ;
	}
	printf("%lld\n", best);
	return 0;
}
