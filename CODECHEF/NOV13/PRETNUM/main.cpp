#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 1000005ULL
#define LIM 1000000000005ULL
using namespace std;
bool p[MAX], p2[MAX];
unsigned long long int primos[79000];
int cantp;
vector<unsigned long long int> v;
void generar() {
  fill(p, p + MAX, true);
  p[0] = p[1] = false;

  for(int i = 4 ; i < MAX; i += 2)p[i] = false;

  for(int i = 3; i * i < MAX; i += 2)
    if(p[i])
      for(int j = i + i; j < MAX; j += i)
        p[j] = false;
  cantp = 0;
  primos[cantp++] = 2;
  for(int i = 3; i < MAX; i += 2)
    if(p[i])
      primos[cantp++] = i;
  //Solucion - Generamos potencias de primos
  for(int i = 0; i < cantp; i++) {
    unsigned long long int num = primos[i] * primos[i];
    int div = 3;//cant de divisores
    while(num <= LIM) {
      if(p[div])
        v.push_back(num);
      num *= primos[i];
      div++;
    }
  }
  sort(v.begin(), v.end());
}
int main() {
  freopen("in", "r", stdin);
  generar();
  int t;
  unsigned long long int a,b;
  scanf("%d", &t);
  while(t--) {
    scanf("%llu %llu", &a, &b);
    if(a == 1)a++;
    fill(p2, p2 + MAX, true);
    int ptr = 0;
    while(primos[ptr] * primos[ptr] <= b) {
      unsigned long long int ini = a;
      if(a % primos[ptr] != 0 ) ini += (primos[ptr] - (a % primos[ptr]));//el siguiente multiplo de primos[ptr]
      if(ini <= primos[ptr]) ini += primos[ptr];//Si es primo
      while(ini <= b) {
        p2[ini - a] = false;
        ini += primos[ptr];
      }
      ptr++;
    }
    unsigned long long int ans = 0, primos = 0;
    for(unsigned long long int i = a; i <= b; i++)
      if(p2[i - a])
        primos++;
    a = lower_bound(v.begin(), v.end(), a) - v.begin();
    b = upper_bound(v.begin(), v.end(), b) - v.begin();
    ans = primos + (b - a);
    printf("%llu\n", ans);
  }
  return 0;
}
