#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int cp[10] = {0};
void imprimir(int *vec, int n) {
  forn (i, n)
    cout << vec[i] << " ";
  cout << endl;
}
void f() {
  imprimir(v, 10);
  imprimir(cp, 10);
}
int main() {
  f();
  memcpy(cp + 1, v, sizeof(int) * 9);
  f();
  return 0;
}
