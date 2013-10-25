#include <cstdio>
#include <cstring>
#include <fstream>
#define MAX 131075
using namespace std;
char cad[MAX];
struct set{
  bool esta[MAX];
  int tam;
  void clear(){
    memset(esta, false, sizeof(esta));
    tam = 0;
  }
  void insert(int n){
    if(!esta[n]){
      esta[n] = true;
      tam++;
    }
  }
  int size(){
    return tam;
  }
};
int main() {
  freopen("in", "r", stdin);
  int t;
  scanf("%d", &t);
  set myset;
  while(t--) {
    scanf("%s", cad);
    int ans = strlen(cad);
    int lim = ans;
    for(int n = 1; n <= lim; n++) {
      myset.clear();
      int num = 0;
      for(int i = 0; i < n - 1; i++)
        num = (num<<1) | (cad[i]-'0');
      for(int i = n - 1; i < lim; i++){
        num = ((num<<1) & ((1<<n)-1)) | (cad[i]-'0');
        myset.insert(num);
      }
      if(myset.size() < (1<<n)){
        ans = n;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
