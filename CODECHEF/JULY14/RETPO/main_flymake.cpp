#include <bits/stdc++.h>
using namespace std;
typedef long long int Number;
int main(){
  int t;
  Number x, y;
  scanf("%d", &t);
  while(t--){
    scanf("%lld%lld", &x, &y);
    Number with = abs(x);
    Number height = abs(y);
    Number dif = abs(with - height);
    Number ans = 2 * max(with, height);
    if(dif & 1)ans++;
    if(height > with && (dif & 1LL))
      ans -= 2;
    printf("%lld\n", ans);
  }
  return 0;
}
