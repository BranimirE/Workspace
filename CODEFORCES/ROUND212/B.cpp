#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n, m, v[3005];
  bool sw;
  while(scanf("%d %d", &n, &m) == 2){
    sw = false;
    for(int i = 0; i < m; i++){
      scanf("%d", &v[i]);
      sw |= (v[i] == 1 || v[i] == n);
    }
    if(sw == false){
      sort(v, v + m);
      for(int i = 0; i + 2 < m && sw == false; i++)
        sw = (v[i] + 1 == v[i + 1]) && (v[i + 1] + 1 == v[i + 2]);
    }
    puts(sw?"NO":"YES");
  } 
  return 0;
}
