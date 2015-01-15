#include <cstdio>
#define MAX 1000010

using namespace std;

char c[MAX];
int b[MAX];
int n;
int main(){
  int t;
  scanf("%d", &t);
  for(int caso = 1; caso <= t; caso++){
    scanf("%d", &n);
    scanf("%s", &c);
    int i, j;
    i = 0, j = -1;
    b[i] = j;
    while(i < n){
      while(j >= 0 && c[i] != c[j]) j = b[j];
      i++, j++;
      b[i] = j;
    }
    if(caso != 1)puts("");
    printf("Test case #%d\n", caso);
    for(i = 2; i <= n; i++){
      int bor = b[i];
      while(bor > 0 && i % bor != 0) bor = b[bor];

      if(bor > 0 && i % bor == 0){
        bool match = true;
        for(int a = bor; a < i && match; a++)
          match = (c[a] == c[a - bor]);
        if(match)
          printf("%d %d\n", i, i / bor);
      }
    }
  }
  return 0;
}
