#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
  int n, m;
  scanf("%d%d\n", &n, &m);
  char v[n + 10];
  int c[10];
  int ans[n + 3];
  memset(c, 0, sizeof(c));
  gets(v);
  for(int i = 0; i < n; i++){
    int d = v[i] - '0';
    ans[i] = 0;
    for(int j = 0; j < 10; j++)
      ans[i] += (abs(d - j) * c[j]);
    c[d]++;
  }
  while(m--){
    int q;
    scanf("%d", &q);
    printf("%d\n", ans[q - 1]);
  }
  return 0;
}
