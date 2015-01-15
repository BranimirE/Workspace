#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

int main() {
  int t, R, G, B, k, r, g, b, tmp;
  
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &R, &G, &B, &k);
    r = g = b = 0;
    while (R--) {
      scanf("%d", &tmp);
      r = max(r, tmp);
    }
    while (G--) {
      scanf("%d", &tmp);
      g = max(g, tmp);
    }
    while (B--) {
      scanf("%d", &tmp);
      b = max(b, tmp);
    }
    int v[3] = {r, g, b};
    while (k--) {
      sort(v, v + 3);
      v[2] >>= 1;
    }
    sort(v, v + 3);
    printf("%d\n", v[2]);
  }
  return 0;
}
