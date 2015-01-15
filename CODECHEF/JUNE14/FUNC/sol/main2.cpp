#include <bits/stdc++.h>
#define MOD 1000000007LL
#define MAX 10000
using namespace std;
typedef long long int Number;
Number a[MAX + 5];
Number sum[MAX + 5];
int n, q;
Number powf(Number b, int e){
  if(e == 0)
    return 1LL;
  Number ans = powf(b, e >> 1);
  ans = ans * ans;
  if(e & 1)
    ans *= b;
  //cout << "pow(" << b << "," << e << ")" ;
  //cout << " -> " << ans << endl;
  return ans;
}
Number root(int i, Number num){
  //cout << "entra i = " << i << " num = " << num << endl;
  Number x = 1;
  bool decreased = false;
  while(true){
    assert(i > 0);
    
    Number nx = ((num / powf(x, i - 1)) + (x * (i - 1))) / i;
    cout << "nx = " << nx << endl;
    if(x == nx || nx > x && decreased) 
      break;
    decreased = nx < x;
    x = nx;
  }
  cout << "sale" << endl;
  return x;
}
int main(){
  /*
  int t;
  Number x;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
      scanf("%lld", &a[i]);
      a[i] %= MOD;
    }
    sum[n + 1] = 0;
    for(int i = n; i >= 1; i--){
      sum[i] = (a[i] + sum[i + 1]) % MOD;
    }
    while(q--){
      scanf("%lld", &x);
      Number ans = 0;
      for(int i = 1; i <= n; i++){
        Number rr = root(i, x);
        if(rr > 1){
          if(rr >= MOD) rr %= MOD;
          ans = (ans + rr * a[i]) % MOD;
        }
        else{
          ans = (ans + sum[i]) % MOD;
          break;
        }
      }
      printf("%lld\n", ans);
    }
    }*/
  cout << root(9, 1542668056LL) << endl;
  //cout << root(2, 9) << endl;
  return 0;
}
