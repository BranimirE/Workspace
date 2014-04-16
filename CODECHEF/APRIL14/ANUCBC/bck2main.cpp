#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 100000
#define MOD 1000000009LL
typedef long long int Number;

char line[1200000];//OJO maximo mas 3 para el '\n' y el '\0'
int now = 0;
inline Number getInt(){
  Number n;
  Number sign = 1;
  while(true)
    if(line[now] != 0){
      if(line[now] == '-'){
        sign = -1;
        now++;
        continue;
      }
      if(line[now] < '0' || line[now] > '9'){
        now++;
        continue;
      }
      n = 0;
      while(line[now] >= '0' && line[now] <= '9') {
        n = n * 10 + line[now] - '0';
        now++;
      }
      return sign * n;
    }
    else{
      gets(line);
      now = 0;
    }
  return sign * n;
}

Number v[MAX + 5];
int c[100];
int n;
Number bags;
Number mod(Number a, Number b){
  Number ans = a % b;
  if(ans < 0)
    ans += b;
  return ans;
}
Number dp[101][101];
Number f[MAX + 5];
Number pow(Number b, Number e){
  if(e == 0) return 1LL;
  Number ans = pow(b, (e >> 1LL));
  ans = ans * ans;
  if(ans >= MOD) ans %= MOD;
  if(e & 1){ 
    ans = ans * b;
    if(ans >= MOD) ans %= MOD;
  }
  return ans;
}
Number C(Number n, Number k){
  return (f[n] * pow((f[k] * f[n-k]) % MOD , MOD - 2)) % MOD;
}
Number mul[101][101];

Number solve(int pos, int obj){
  if(pos == bags) 
    return Number(obj == 0);
  Number &ans = dp[pos][obj];
  if(ans != -1) 
    return ans;
  ans = solve(pos + 1, obj);
  for(int modu = 0; modu < bags; modu++){
    Number mm = mod(obj - modu, bags);
    ans = (ans + ((solve(pos + 1, mm) * mul[pos][modu]) % MOD)) % MOD;
  }
  return ans;
}
Number solve2(){
  dp[bags][0] = 1;
  for(int i = 1; i < bags; i++)
    dp[bags][i] = 0;
  for(int pos = bags - 1; pos >= 0; pos--)
    for(int obj = 0; obj < bags; obj++){
      dp[pos][obj] = dp[pos + 1][obj];
      for(int modu = 0; modu < bags; modu++){
        Number mm = mod(obj - modu, bags);
        dp[pos][obj] += dp[pos + 1][mm] * mul[pos][modu];
        if(dp[pos][obj] > MOD)
          dp[pos][obj] %= MOD;
      }
    }
  return dp[0][0];
}
int main(){
  int t;
  int q;
  f[0] = 1;
  for(int i = 1; i <= MAX; i++)
    f[i] = (i * f[i-1]) % MOD;
  //scanf("%d", &t);
  t = getInt();
  while(t--){
    //scanf("%d%d", &n, &q);
    n = getInt();
    q = getInt();
    for(int i = 0; i < n; i++){
      //scanf("%lld", &v[i]);
      v[i] = getInt();
    }
    while(q--){
      //scanf("%lld", &bags);
      bags = getInt();
      memset(c, 0, sizeof(c));
      for(int i = 0; i < n; i++)
        c[mod(v[i], bags)]++;

      memset(mul, 0, sizeof(mul));
      for(int pos = 0; pos < bags; pos++)
        for(int cant = 1; cant <= c[pos]; cant++)
          mul[pos][pos*cant % bags] = (mul[pos][pos*cant % bags] + C(c[pos], cant)) % MOD;

      memset(dp, -1, sizeof(dp));
      printf("%lld\n", solve2());
    }
  }
  return 0;
}
