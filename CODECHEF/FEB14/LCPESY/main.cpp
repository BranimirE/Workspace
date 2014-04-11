#include <cstdio>
#include <cstring>
using namespace std;
char c[10010];
int a[300], t, ans;
int main() {
  scanf("%d", &t);
  while(t--){
    scanf("%s", c);
    memset(a, 0, sizeof(a));
    for(int i = 0, s = strlen(c); i < s; i++)
      a[c[i]]++;
    scanf("%s", c);
    ans = 0;
    for(int i = 0, s = strlen(c); i < s; i++)
      if(a[c[i]])
        ans++, a[c[i]]--;
    printf("%d\n", ans);
  }
  return 0;
}
