#include <bits/stdc++.h>

using namespace std;
char c[123456];
int n;
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    scanf("%s", c);
    long long int ans = 0;
    for(int i = 0; i < n; i++)
      if(c[i] == '1')
        ans++;
    printf("%lld\n", ans * (ans + 1LL) / 2LL);
  }
  return 0;
}
