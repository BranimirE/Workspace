#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
typedef long long int Number;
int n, k;
Number obj;
Number libre[10];
Number peso[30];

//OPTIMIZACIONES
// - Puedo completar con el mas pequeño el actual que llene?
// - Intento asignar en uno que tiene el mismo espacio libre, probar solo en uno igual que poner en los demas

bool solve(int i) {//i-esimo objeto
  if (i == n) return true;
  bool ans = false;
  for (int j = 0; j < k && !ans; j++) {

    bool repetido = false;
    for (int jj = 0; jj < j; jj++)
      if (libre[jj] == libre[j]) {
	repetido = true;
	break;
      }    
    if (repetido) continue;

    if (peso[i] <= libre[j]) {
      libre[j] -= peso[i];

      //hay un pequeño espacio aun vacio, pero tal vez el objeto mas pequeño sea muy grande
      if (libre[j] > 0 && (i != (n - 1) && peso[n-1] > libre[j] )) {
	libre[j] += peso[i];
	continue;
      }
      
      ans |= solve(i + 1);
      libre[j] += peso[i];
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    Number sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &peso[i]);
      sum += peso[i];
    }
    sort(peso, peso + n);
    reverse(peso, peso + n);
    if ((sum % Number(k)) != 0 || (sum / Number(k)) < peso[0] || n < k) {
      printf("no\n");
    } else {
      obj = sum / Number(k);
      for (int i = 0; i < k; i++) {
	libre[i] = obj;
      }
      printf(solve(0)?"yes\n":"no\n");
    }
  }
  return 0;
}
