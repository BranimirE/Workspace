#include <bits/stdc++.h>
#define MAX 1000010
#define MOD 1000000007LL
using namespace std;
typedef long long int Number;
bool isprime[MAX];
vector<int> primes;
void generatePrimes(){
  fill(isprime, isprime + MAX, true);
  isprime[1] = isprime[0] = false;
  for(int i = 4; i < MAX; i += 2)
    isprime[i] = false;
  for(int i = 3; i * i < MAX; i += 2)
    if(isprime[i])
      for(int j = i + i; j < MAX; j += i)
        isprime[j] = false;
  for(int i = 0; i < MAX; i++)
    if(isprime[i])
      primes.push_back(i);
}
map<int,int> memo[MAX];
bool factorized[MAX];
map<int,int> factorize(int N){
  if(factorized[N] || N<=1)
    return memo[N];
  map<int,int> &ans = memo[N];
  if(isprime[N]){
    ans[N]++;
    factorized[N] = true;
    return ans;
  }
  int i = 0;
  while(primes[i] * primes[i] <= N){
    if(N % primes[i] == 0){
      ans = factorize(N / primes[i]);
      ans[primes[i]]++;
    }
    i++;
  }
  factorized[N] = true;
  return ans;
}
Number modPow(Number base, int power){
  if(power == 0)
    return 1LL;
  Number ans = modPow(base, power >> 1);
  ans = ans * ans;
  if(power & 1)
    ans = (ans * base);
  return ans;
}
int main(){
	int var = 5000;
	while(var--){
		cout << 1000000000 <<" ";
	}
	cout << endl;
	return 0;
}
