#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define MAXN 100010
typedef unsigned long long int Number;
char v[MAXN];
int n;
Number ans, acu;
const Number MOD = 1000000009LL;

int main() {
  int t, buck;
  char paint;
  int pos;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &buck);
    for (int i = 1; i <= n; i++)
      v[i] = ' ';
    int ini = INT_MAX, fin = INT_MIN;
    while (buck--) {
      cin >> paint >> pos;
      v[pos] = paint;
      ini = min(ini, pos);
      fin = max(fin, pos);
    }
    int cur = '$';
    ans = 1;
    acu = 1;
    
    for (int i = ini; i <= fin; i++) {
      if (v[i] == ' ') {
	acu++;
      } else {
	ans = (ans * acu) % MOD;
	acu = 1LL;
	cur = v[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
