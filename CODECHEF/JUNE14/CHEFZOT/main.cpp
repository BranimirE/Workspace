#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, ans = 0, cnt = 0, tmp;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &tmp);
    if(tmp == 0)cnt = 0;
    else cnt++;
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
