#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
vector<int> have;
bool in_set[1234];
int n, k, ans, num, tmp;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    have.clear();
    have.pb(0);
    memset(in_set, false, sizeof(in_set));
    ans = k;
    while (n--) {
      scanf("%d", &num);
      for (int i = 0, s = sz(have); i < s; i++) {
	tmp = num ^ have[i];
	if (!in_set[tmp]) {
	  have.pb(tmp);
	  in_set[tmp] = true;
	  ans = max(ans, k ^ tmp);
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
