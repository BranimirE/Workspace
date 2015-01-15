#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int score[MAXN];
int own[MAXN];
int n;
int getOwn(int e){
  if(own[e] == e)
    return e;
  return own[e] = getOwn(own[e]);
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      scanf("%d", &score[i]);
      own[i] = i;
    }
    int queries;
    int op, x, y;
    scanf("%d", &queries);
    while(queries--){
      scanf("%d", &op);
      if(op == 0){
        scanf("%d%d", &x, &y);
        x = getOwn(x);
        y = getOwn(y);
        if(x == y)
          printf("Invalid query!\n");
        else{
          if(score[x] != score[y]){
            if(score[x] > score[y])
              swap(x, y);
            own[x] = y;
          }
        }
      }else{
        scanf("%d", &x);
        int ans = getOwn(x);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
