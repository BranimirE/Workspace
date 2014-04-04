#include <cstdio>
using namespace std;
int max(int a, int b){return a>b?a:b;}
int main() {
  int t, n, ans, num;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    ans = 0;
    for(int d = 0; d < n; d++){
      scanf("%d", &num);
      ans = max(ans, d + num);
    }
    printf("%d\n", ans);
  }
  return 0;
}
