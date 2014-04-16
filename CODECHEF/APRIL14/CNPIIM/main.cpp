#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 2510
using namespace std;
typedef long long int Number;
vector<Number> primes;
void generatePrimes(){
  bool m[MAXN];
  memset(m, 0, sizeof(m));
  for(int i = 2; i * i < MAXN; i++)
    if(!m[i])
      for(int j = i + i; j < MAXN; j += i)
        m[j] = true;
  for(int i = 2; i < MAXN; i++)
    if(!m[i])
      primes.push_back(i);
}
int d[1600000];
int divisors(int n){
  if(d[n] != -1)
    return d[n];
  int nn = n;
  int ans = 1;
  int i = 0;
  while(primes[i] * primes[i] <= n){
    int c = 0;
    while(n % primes[i] == 0){
      c++;
      n /= primes[i];
    }
    ans *= (c + 1);
    if(d[n] != -1){
      ans *= d[n];
      return d[nn] = ans;
    }
    i++;
  }
  if(n > 1)
    ans *= 2;
  return ans;
}

int main(){
  generatePrimes();
  int t, tmp, maxi = 1;
  vector<int> q;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d", &tmp);
    q.push_back(tmp);
    maxi = max(maxi, tmp);
  }
  maxi = maxi / 2 + 1;
  maxi = maxi * maxi;
  int mul[maxi];
  mul[0] = 0;
  memset(d, -1, sizeof(d));
  for(int i = 1; i < maxi; i++)
    mul[i] = mul[i - 1] + divisors(i);
  for(int i = 0; i < t; i++){
    Number ans = 0;
    for(int j = 1; j < q[i]; j++)
      ans += mul[j * (q[i] - j) - 1];
    printf("%lld\n", ans);
  }
  return 0;
}
