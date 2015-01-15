#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int sqr(int x) { return x * x;}
int n;
int x[30], y[30];
int target;
int dist(int i, int j) {
  return sqr(x[j] - x[i]) + sqr(y[j] - y[i]);
}
int dp[25][(1<<24)];
int solve(int pos, int mask) {
  int &ans = dp[pos][mask];
  if (ans != -1) return ans;
  
  if (mask == target)
    return ans = dist(0, pos);
  ans = (1 << 30);
  if (pos != 0) {
    for (int i = 0; i <= n; i++)
      if (!(mask & (1 << (i - 1))))
	ans = min(ans, dist(pos, i) + dist(i, 0) + solve(0, mask | (1 << (i - 1))));
  } else {
    for (int i = 1; i <= n; i++)
      if (!(mask & (1 << (i - 1))))
	ans = min(ans, dist(pos, i) + solve(i, mask | (1 << (i - 1))));
  }  
  return ans;
}
void path(int pos, int mask, vector<int> & ans) {
  if (mask == target) {
    if (pos != 0)
      ans.pb(0);
    return;
  }
  int best = dp[pos][mask], tmp, a, b;

  if (pos != 0) {
    for (int i = 0; i <= n; i++)
      if (!(mask & (1 << (i - 1)))) {
	tmp = dp[0][mask | (1 << (i - 1))];
	a = dist(pos, i);
	b = dist(i, 0);
	if ((best - a - b) == tmp) {
	  ans.pb(i);
	  ans.pb(0);
	  path(0, mask | (1 << (i - 1)), ans);
	  return;
	}
      }
  } else {
    for (int i = 1; i <= n; i++)
      if (!(mask & (1 << (i - 1)))) {
	a = dist(pos, i);
	if (best == (dp[i][mask | (1 << (i - 1))] + a)) {
	  ans.pb(i);
	  path(i, mask | (1 << (i - 1)), ans);
	  return;
	}
      }

  }  

}
int main() {
  scanf("%d %d", &x[0], &y[0]);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &x[i], &y[i]);
  target = (1 << n) - 1;
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(0, 0));
  vector<int> ans;
  ans.pb(0);
  path(0, 0, ans);
  forn (i, sz(ans)) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
