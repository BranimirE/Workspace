#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
set<int> s;
int main() {
  int t, n, tmp;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    s.clear();
    while (n--) {
      scanf("%d", &tmp);
      s.insert(tmp);
    }
    printf("%d\n", sz(s));
  }
  return 0;
}
