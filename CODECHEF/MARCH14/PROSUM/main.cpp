#include <cstdio>
using namespace std;
 
int main() {
  long long int t, n, tmp, ans, ohs, ones, twos;
  scanf("%lld", &t);
  while(t--){
    scanf("%lld", &n);
    ans = 0;
    twos = ones = ohs = 0;
    for(int i = 0; i < n; i++){
      scanf("%lld", &tmp);
      if(tmp != 1 && tmp != 0){
        if(tmp == 2)
          ans += i - twos - ohs - ones;
        else
          ans += i - ohs - ones;
      }
      if(tmp == 0) ohs++;
      if(tmp == 1) ones++;
      if(tmp == 2) twos++;
    }
    printf("%lld\n", ans);
  }
  return 0;
} 
