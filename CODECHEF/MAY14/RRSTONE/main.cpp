#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int Number;
Number v[123456];
int n;
Number k, MAX;
void solve(){
  MAX = *max_element(v, v + n);
  for(int i = 0; i < n; i++)
    v[i] = MAX - v[i];
}
int main(){
  scanf("%d%lld", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%lld", &v[i]);
  if(k){
    solve();
    k = (k - 1) % 2LL;
    if(k)
      solve();
  }
  for(int i = 0; i < n; i++)
    printf("%s%lld", i?" ":"", v[i]);
  puts("");
  return 0;
}
