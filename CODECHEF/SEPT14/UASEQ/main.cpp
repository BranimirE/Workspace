#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN 100010
typedef long long int Number;
int n, k;
Number v[MAXN];
bool check(Number ini, Number diff) {
  int count = 0;
  for (int i = 0; i < n && count <= k; i++) {
    if (v[i] != ini)
      count++;
    ini += diff;
  }
  return count <= k;
}
int main() {
  scanf("%d %d", &n, &k);
  forn (i, n)
    scanf("%lld", &v[i]);
  set<pair<Number, Number> > s;
  if (n <= 21) {
    forn (i, n)
      for (int j = i + 1; j < n; j++) {
	Number a = v[j] - v[i];
	Number b = j - i;
	if (a % b == 0) {
	  Number d = a / b;
	  s.insert(mp(v[i] - i * d, d));
	}
      }
  } else {
    for (int i = 0; (i + 1) < n; i++) {
      Number d = v[i + 1] - v[i];
      s.insert(mp(v[i] - i * d, d));
    }
  }
  for (pair<Number, Number> ans: s) {
    Number ini = ans.first;
    Number diff = ans.second;
    if (check(ini, diff)) {
      forn (i, n) {
	if (i) printf(" ");
	printf("%lld", ini);
	ini += diff;
      }
      printf("\n");
      break;
    }
  }
  return 0;
}
