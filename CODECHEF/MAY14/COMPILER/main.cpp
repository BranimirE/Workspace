#include <cstdio>
#include <cstring>
using namespace std;
char c[1000050];
int main(){
  int t;
  scanf("%d", &t);
  getchar();
  while(t--){
    gets(c);
    int n = strlen(c), open = 0;
    int ans = 0, current = 0;
    for(int i = 0; i < n; i++){
      if(c[i] == '<')
        open++;
      if(c[i] == '>'){
        if(open){
          current += 2;
          open--;
          if(open == 0){
            ans += current;
            current = 0;
          }
        }else{
          break;
        }
      }
    } 
    printf("%d\n", ans);
  }
  return 0;
}
