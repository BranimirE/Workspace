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
  return ans;
}
Number root(int i, Number num){
  Number ans = Number(floor(pow(double(num), double(1.0) / double(i))));
  if(pow(ans, i) == num) 
    return ans;

  while(pow(ans + 1, i) <= num)
    ans++;

  while((ans - 1) >= 1 && pow(ans - 1, i) > num)
    ans--;
  /*
  Number tmp1 = 1, tmp2 = 1;
  for(int j = 0; j < i; j++){
    tmp1 = tmp1 * ans;
    tmp2 = tmp2 * (ans + 1);
  }
  // cout << "i = " << i << " x = " << num << endl;
  assert(tmp1 <= num && tmp2 > num);*/
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
      printf("%lld\n", ans);
    }
  }
  return 0;
}
