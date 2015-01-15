#include <bits/stdc++.h>
#define MAX 200001
#define MAXA 101
#define MOD 1000000007LL
using namespace std;
char line[1000000];
int now = 0;
inline int getInt(){
  int n;
  while(true)
    if(line[now] != 0){
      if(line[now] < '0' || line[now] > '9'){
        now++;
        continue;
      }
      n = 0;
      while(line[now] >= '0' && line[now] <= '9') {
        n = n * 10 + line[now] - '0';
        now++;
      }
      return n;
    }
    else{
      gets(line);
      now = 0;
    }
  return n;
}

typedef long long int Number;
int n;
int a[MAX + 5];
int next[MAXA][MAX + 3];//[num][pos]
Number dp[MAX + 1];
Number solve(int pos, int diff){
  int sig = a[pos] + diff;
  if(sig < 1 || sig > 100)
    return 1LL; //el actual
  
  Number &ans = dp[pos];
  if(ans != -1LL)
    return dp[pos];
  
  ans = 1LL;// current
  int add = pos;
  while((add = next[sig][add + 1]) >= 0){
    ans += solve(add, diff);
    if(ans >= MOD) ans %= MOD;
  }
  return ans;
}
Number pow(int e){
  if(e == 0)
    return 1LL;
  Number ans = pow(e >> 1);
  ans = ans * ans;
  
  if(ans >= MOD) ans %= MOD;
  
  if(e & 1)
    ans <<= 1LL;
  
  if(ans >= MOD) ans %= MOD;
  
  return ans;
}
int main(){
  
  int t;
  t = getInt();
  while(t--){
    n = getInt();
    memset(next, -1, sizeof(next));
    int maxi = 0;
    for(int i = 0; i < n; i++){
      a[i] = getInt();
      maxi = max(maxi, a[i]);
    }

    for(int i = n - 1; i >= 0; i--){
      for(int j = 0; j <= maxi; j++)
        next[j][i] = next[j][i + 1];
      next[a[i]][i] = i;
    }
    
    Number ap = 1;//empty
    int tmp ;
    for(int diff = -99; diff < 100; diff++){
      memset(dp, -1, sizeof(dp));
      for(int i = 0; i < n; i++){
        ap += solve(i,  diff) - 1LL;
        if(ap >= MOD)
          ap %= MOD;
      }
    }
    ap = (ap + MOD + n) % MOD;
    printf("%lld\n", (pow(n) - ap + MOD + MOD) % MOD );
  }
  return 0;
}
