#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;
int n;
long long int izq, der, aizq, ader;
long long int v[100005];

int main(){
  while(cin >> n >> izq >> der >> aizq >> ader){
    for(int i = 1; i <= n; i++){
      cin >> v[i];
      v[i] += v[i-1];
    }
    long long int ans = LLONG_MAX, sizq, sder, a,b;
    for(int i = 0; i <= n; i++){
      sizq = v[i];
      sder = v[n] - v[i];
      a = i;//elementos izq
      b = n - i;//elementos der
      if(b > a){// mas elementos a la derecha
        ans = min(ans, sizq * izq + sder * der + (b - a - 1)*ader);
      }else if(a > b)
        ans = min(ans, sizq * izq + sder * der + (a - b - 1)*aizq);
      else // iguales
        ans = min(ans, sizq * izq + sder * der);
    }
    cout << ans << endl;
  }
  return 0;
}
