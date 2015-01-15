#include <cstdio>
#include <algorithm>

#define MAX 1000005
using namespace std;
int v[MAX], n, k, b;
bool solve(int d){
  int maq = 0, bat = 0;
  for(maq = 0; maq < n; maq++){
    while(bat + 1 < b && v[bat+1]-v[bat] > d)
      bat++;//avanzo los que su diff es mas grande
    //verifico que aun alcanza para distribuir al resto
    if(v[bat+1]-v[bat] <= d && (b - bat) >= (n-maq)*2*k)
      bat += 2;//pruebo con el resto
    else
      return false;// estricatemente tiene que ser mas grande
  }
  return (maq == n);//es muy grande pero podria ser la respuesta
}
int main(){
  while(scanf("%d %d", &n, &k) == 2){
    b = 2 * n * k;//baterias
    for(int i = 0; i < b; i++)
      scanf("%d", &v[i]);
    sort(v, v + b);
    int l = 0, r = 1000000000, d;
    while(l < r){
      d = (l + r)/2;
      if(solve(d))
        r = d;//podria ser ese
      else
        l = d + 1;//estrictamente mas grande
    }
    printf("%d\n", l);
  }
  return 0;
}
