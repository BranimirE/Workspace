#include <bits/stdc++.h>
#define MAX 100010
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
Number modPow(Number base, int power, Number mod){
  if(power == 0)
    return 1LL;
  Number ans = modPow(base, power >> 1, mod);
  ans = (ans * ans) % mod;
  if(power & 1)
    ans = (ans * base) % mod;
  return ans;
}
int vec[MAX];
bool vis[MAX];
bool cicles[MAX];
int divi[MAX];
int main(){  
  generatePrimes();
  int t, n;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &vec[i]);
      vec[i]--;
      vis[i] = false;
      cicles[i] = false;
    }
    memset(divi, 0, sizeof(divi));
    Number ans = 1;
    int maxbase = 0;
    for(int i = 0; i < n; i++)
      if(vis[i] == false){
        vis[i] = true;
        int cnt = 1;
        int sig = vec[i];
        while(sig != i){
          cnt++;
          vis[sig] = true;
          sig = vec[sig];
        }
        if(cicles[cnt] == false){
          cicles[cnt] = true;
          map<int,int> f = factorize(cnt);
          map<int, int>::iterator it;
          for(it = f.begin(); it != f.end(); it++){
            int base = it->first;
            int power = it->second;
            divi[base] = max(divi[base], power);
            maxbase = max(maxbase, base);
          }
        }
     }
    for(int i = 2; i <= maxbase; i++)
      ans = (ans * modPow(i, divi[i], MOD)) % MOD;
    printf("%lld\n", ans);
  }
  return 0;
}
