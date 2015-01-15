#include <cstdio>
//#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
int r[10];
int d[10000];
int cola[10005];//queue<int> cola;
int main(){
  //freopen("in", "r", stdin);
  int ini, obj, v, caso = 1, act, ady;
  while(scanf("%d%d%d", &ini, &obj, &v) and !(!ini and !obj and !v)){
    for(int i = 0; i < v; i++)
      scanf("%d", &r[i]);
    memset(d, -1, sizeof(d));
    d[ini] = 0;
    cola[0] = ini;//cola.push(ini);
    int k = 1;
    for(int j = 0; j < k; j++){//while(!cola.empty()){
      act = cola[j];//act = cola.front(); cola.pop();
      for(int i = 0; i < v; i++){
        ady = (act + r[i]);
        if(ady >= 10000) ady -= 10000;
        if(d[ady] == -1){
          d[ady] = d[act] + 1;
          cola[k++] = ady;//cola.push(ady);
          if(ady == obj)break;
        }
      }
    }
    printf("Case %d: ", caso++);
    if(d[obj] == -1)
      puts("Permanently Locked");
    else
      printf("%d\n", d[obj]);
  }
  return 0;
}
