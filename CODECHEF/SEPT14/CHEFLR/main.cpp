#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007LL
typedef long long int Number;
char c[100010];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", c);
    int n = strlen(c);
    Number cur = 1;
    forn (i, n) {
      cur <<= 1LL;
      if (c[i] == 'r') {
	if (i & 1)
	  cur++;
	else
	  cur += 2LL;
      } else {
	if (i & 1)
	  cur--;
      }
      while (cur >= MOD) cur -= MOD;
    }
    printf("%lld\n", cur);
  }
  return 0;
}
