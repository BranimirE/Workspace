#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long int d[35], w, lib;

bool sel[35][1005], sol[35];//para reconstruccion (*)
int cant ; // * cantidad de elementos tomados

long long int dp[35][1005], v[35], p[35];//dp[OBJETOS + 1][LIBRE + 1]
long long int mochila(int i, int libre) { // Llamar mochila(N-1, libre)
  if(i < 0)return 0LL;
  long long int &ans = dp[i][libre];
  if(ans != -1) return ans;
  ans = mochila(i-1, libre);// no lo tomo
  if(p[i] <= libre){ // si cabe en el espacio disponible
    ans = max(ans ,v[i] + mochila(i-1, libre - p[i])); // pruebo si lo tomaria
    if(ans ==  v[i] + mochila(i-1, libre - p[i]))//* si se tomo el objeto
      sel[i][libre] = true;//* marco como tomado
  }
  return ans;
}
//* Marca en el vector sol[ELEMEMTOS] los elementos que fueron tomados
void reconstruir(int i, int libre){
  if(i < 0) return;
  if(sel[i][libre]){//si fue seleccionado
    sol[i] = true;//marco
    cant++;
    reconstruir(i-1, libre - p[i]);
  }else
    reconstruir(i-1, libre);
}

int main() {
  int n;
  bool enter = false;
  while(scanf("%lld %lld ", &lib, &w) == 2) {
    if(enter)puts("");
    enter = true;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%lld %lld", &d[i], &v[i]);
      p[i] = w*d[i] + 2LL*w*d[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(sel, false, sizeof(sel));
    printf("%lld\n", mochila(n-1, lib));
    memset(sol, false, sizeof(sol));
    cant = 0;
    reconstruir(n-1, lib);
    printf("%d\n", cant);
    for(int i = 0; i < n; i++)
      if(sol[i])
        printf("%lld %lld\n", d[i], v[i]);
  }
  return 0;
}
