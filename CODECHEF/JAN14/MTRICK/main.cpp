#include <cstdio>
using namespace std;

#define MAX 1010
#define DER 1
#define IZQ 0
typedef unsigned long long int Number;
Number v[MAX];
char c[MAX];
int n;
Number multi(Number a, Number b, Number mod){
  if(b == 0ULL) return 0ULL;
  Number ans = (multi( a, b / 2ULL, mod ) * 2ULL) % mod;
  if(b % 2ULL == 1ULL) ans = (ans + a) % mod;
  return ans;
}
int main(){
  int t;
  Number sum, mul, mod;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%llu", &v[i]);
    scanf("%llu %llu %llu", &sum, &mul, &mod);
    scanf("%s", c);
    int pos = 0;
    bool dir = DER;
    Number asum = 0, amul = 1;
    sum %= mod;
    mul %= mod;
    for(int i = 0; i < n; i++){
      if(c[i] == 'R'){
        int res = n - i - 1;
        if(dir == DER)
          pos += res;
        else
          pos -= res;
        dir = !dir;
      }else if(c[i] == 'A'){
        asum += sum;
        if(asum > mod)asum -= mod;
      }else{
        amul = multi(amul, mul, mod);
        asum = multi(asum, mul, mod);
      }
      if(i)printf(" ");
      Number ans = (multi(v[pos]%mod, amul, mod) + asum) % mod;
      printf("%llu", ans);
      if(dir == DER)pos++;
      else pos--;
    }
    puts("");
  }
  return 0;
}
