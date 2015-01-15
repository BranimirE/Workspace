#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int sqr(int x) {
  return x * x;
}
int x[25], y[25];
int n;
int dp[1<<25];
pair<int,int> p[1<<25];
int dist[26][26];
int main() {
  scanf("%d %d", &x[0], &y[0]);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &x[i], &y[i]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dist[i][j] = sqr(x[j] - x[i]) + sqr(y[j] - y[i]);
  int lim = 1 << n;
  fill(dp, dp + lim, 1 << 29);
  dp[0] = 0;
  p[0] = mp(-1, -1);
  for (int mask = 0; mask < lim; mask++)
    for (int i = 0; i < n; i++)
      if (!(mask & (1 << i))) {
	for (int j = i; j < n; j++)
	  if (!(mask & (1 << j))) {
	    int newmask = mask | (1 << i) | (1 << j);
	    int tmp = dp[mask] + dist[0][i + 1] + dist[i + 1][j + 1] + dist[j + 1][0];
	    if (tmp < dp[newmask]) {
	      dp[newmask] = tmp;
	      p[newmask] = mp(i, j);
	    }
	  }
	break;
      }
  vector<int> ans;
  ans.pb(0);
  printf("%d\n", dp[lim - 1]);
  int cur = lim - 1;
  while (true) {
    int a = p[cur].first, b = p[cur].second;
    if (a == -1) break;
    if (a == b) {
      ans.pb(a + 1);
      ans.pb(0);
      cur -= (1 << a);
    } else {
      ans.pb(a + 1);
      ans.pb(b + 1);
      ans.pb(0);
      cur -= (1 << a);
      cur -= (1 << b);
    }
  }
  forn (i, sz(ans)) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
