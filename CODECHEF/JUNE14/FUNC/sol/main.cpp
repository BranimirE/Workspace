#include <bits/stdc++.h>
#define MOD 1000000007LL
#define MAX 10000
using namespace std;
typedef long long int Number;
Number a[MAX + 5];
Number sum[MAX + 5];

int n, q;
Number root(int i, Number num){//i (1-64), num (1 - 10^18)
  Number ans = pow(num, 1.0 / double(i));
  return ans;
}
int main(){
  
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
      printf("%lld\n", (ans + MOD) % MOD);
    }
  }
  //Number ans = root(9, 1542668056LL); -> Casito
  return 0;
}
