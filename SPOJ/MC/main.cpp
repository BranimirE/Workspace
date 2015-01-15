#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
char a[1234], b[1234];
int dp[1010][1010];
int solve(int i, int j) {
  if (i == 0)
    return j * 30;
  if (j == 0)
    return i * 15;
  int &ans = dp[i][j];
  if (ans != -1)return ans;
  ans = (1 << 30);
  if (a[i] == b[j])
    ans = solve(i - 1, j - 1);
  ans = min(ans, min(15 + solve(i - 1, j), 30 + solve(i, j - 1)));
  return ans;
}
int main() {
  while (gets(a + 1) && a[1] != '#') {
    gets(b + 1);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(strlen(a + 1), strlen(b + 1)));
  }
  return 0;
}
