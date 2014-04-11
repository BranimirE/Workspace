#include <cstdio>
#include <cstring>

using namespace std;
char c[100010];
bool solve(){
  int size = strlen(c);
  for(int i = 0; i < size - 1; i++)
    if(c[i] == '1' && c[i + 1] == '0'){
      if(i - 1 >= 0 && c[i - 1] == '0')return true;
      if(i + 2 < size && c[i + 2] == '1')return true;
    }
  return false;
}
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while(t--){
    gets(c);
    puts(solve()?"Good":"Bad");
  }
  return 0;
}
