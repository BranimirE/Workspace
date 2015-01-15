#include<bits/stdc++.h>
typedef long long int Number;
using namespace std;

Number mcm(Number a, Number b) {
  return (a*b) / __gcd(a, b);
}
Number f(Number a, Number d){
  return (a / d) + Number(( a % d ) != 0);
}
vector<int> mask[1058576];
void preprocess(){
  for(int i = 0; i < (1 << 20); i++)
    for(int j = 0; j < 20; j++)
      if(i & ( 1 << j))
        mask[i].push_back(j);
}
Number n, x;
Number ans = 0;
Number V[50];
void solve(Number mult, Number pos, bool even){
  if(pos == n)
    return;
  Number current = mcm(mult, V[pos]);
  if(even)//Now it is odd
    ans += f(x, current);
  else
    ans -= f(x, current);
  solve(current, pos + 1, !even);
  solve(mult, pos + 1, even);
}
int main() {
  //preprocess();

  while(scanf("%lld %lld", &x, &n) && !(x == 0 && n == 0)) {

    for(int i=0; i<n; i++) 
      scanf("%lld", &V[i]);
    /*
    Number s = 0;
    for(int i = 1; i < (1 << n); i++) {
      Number d = 1;
      for(int j = 0; j < mask[i].size(); j++) {
          d = mcm(d, V[mask[i][j]]);
      }
      if(__builtin_popcount(i) & 1) {
        s += f(x, d);
      } else {
        s -= f(x, d);
      }
    }
    printf("%lld\n", s);
    */
    ans = 0;
    solve(1, 0, true);
    printf("%lld\n", ans);
  }

  return 0;
}
