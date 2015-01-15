#include <cstdio>
#include <fstream>
#include <climits>
#include <string>
#include <cmath>

#define MOD 1000000007ULL
using namespace std;
unsigned long long int solve(unsigned long long int e){
  if(e == 0)return 1ULL;
  long long int ans = solve(e >> 1ULL);
  ans = (ans * ans) % MOD;
  if(e & 1)
    ans = (ans << 1ULL) % MOD;
  return ans;
}
int main(){
  //freopen("in", "r", stdin);
  int t;
  unsigned long long int n;
  scanf("%d", &t);
  while(t--){
    scanf("%llu", &n);
    printf("%llu\n", (solve(n) - 1 + MOD) % MOD);
  }
  return 0;
}
