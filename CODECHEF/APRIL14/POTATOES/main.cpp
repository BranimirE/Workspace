#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool isPrime(int n){
  if((n & 1) == 0)
    return n==2;
  int d = 3;
  while(d * d <= n){
    if(n % d == 0)
      return false;
    d += 2;
  }
  return true;
}
int main(){
  vector<int> primes;
  primes.push_back(2);
  int p = 3;
  while(p < 2500){
    if(isPrime(p))
      primes.push_back(p);
    p += 2;
  }
  /*
  int t, x, y, ans;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &x, &y);
    ans = *upper_bound(primes.begin(), primes.end(), x + y) - x - y;
    printf("%d\n", ans);
    }*/
  for(int i = 0; primes[i] <= 100; i++)
    printf("%d, ", primes[i]);
  return 0;
}
