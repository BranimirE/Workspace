#include <bits/stdc++.h>
typedef long long int Number;
using namespace std;
Number odd(Number n){
  return n / 2LL + (n & 1LL);
}
Number even(Number n){
  return n - odd(n);
}
int main(){
  int t;
  Number n, m;
  scanf("%d", &t);
  while(t--){
    scanf("%lld %lld", &n, &m);
    Number a = odd(n) * even(m) + even(n) * odd(m);
    Number b = n * m;
    Number c = __gcd(a, b);
    a /= c;
    b /= c;
    printf("%lld/%lld\n", a, b);
  }
  return 0;
}
