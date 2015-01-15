#include <string.h>
#include <stdio.h>
typedef unsigned long long int Number ;
Number contar(Number n) {
  int cnt = 0;
  while(n) {
    cnt++;
    n >>= 1ULL;
  }
  return cnt;
}
Number memo[65][65];
Number C(Number n, Number k) {
  if(memo[n][k] != -1)return memo[n][k];
  if(k == 0 || k == n)
    return memo[n][k] = 1ULL;
  return memo[n][k] = (C(n - 1, k - 1) + C(n - 1, k));
}
Number solve(Number n) {
  if(n == 0)return 0;
  Number tam = contar(n);
  Number ans = 0, i;
  for(i = 1; i <= tam-1; i++)
    ans += (C(tam - 1, i) * i);
  return ans + solve(n ^ (1ULL<<(tam-1))) + ( n - ((1ULL<<(tam-1))-1ULL));
}
Number solve2(Number n) {
  Number tam = contar(n);
  Number ans = 0, t, i;
  for(t = tam; t >= 1; t--)
    if((1ULL<<(t-1)) & n) {
      for(i = 1; i <= t - 1; i++)
        ans += (C(t - 1, i) * i);
      ans += (( n - ((1ULL<<(t-1ULL))-1ULL)));
      n = (n ^ (1ULL<<(t-1ULL)));
    }
  return ans;
}
char buff[100];
int main() {
  freopen("in", "r", stdin);
  memset(memo, -1, sizeof(memo));
  Number a, b;
  while(gets(buff)) {
    a = b = 0;
    int i = 0;
    for(; buff[i] != ' '; i++)
      a = a*10ULL + (buff[i] - '0');
    i++;
    for(; buff[i]; i++)
      b = b*10ULL + (buff[i] - '0');
    printf("%llu\n", solve2(b) - solve2(a - 1));
  }
  return 0;
}
