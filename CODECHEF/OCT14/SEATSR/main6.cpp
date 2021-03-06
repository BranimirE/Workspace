#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define MAXN 100010
#define oo (1<<29)
char a[MAXN], b[MAXN];
int addorremove, change, maxedit;
int d[2][MAXN];
int from, to;
int n, m;
int solve() {
  if (addorremove == 0)return 0;
  if (n == m && change == 0) return 0;
  from = 0, to = 1;
  fill(d[0], d[0] + m + 1, oo);
  fill(d[1], d[1] + m + 1, oo);
  int offset = maxedit / addorremove;
  for (int i = 0; i <= n; i++) {
    int ini = max(0, i - offset), fin = min(m, i + offset);   
    for (int j = ini; j <= fin; j++) {
      int &ans = d[to][j];
      if (i == 0)
	ans = j * addorremove;
      else if (j == 0)
	ans = i * addorremove;
      else {	
	if (a[i] == b[j])
	  ans = d[from][j - 1];
	else
	  ans = d[from][j - 1] + change;
	ans = min(ans, d[from][j] + addorremove);
	ans = min(ans, d[to][j - 1] + addorremove);
      }
    }
    swap(from, to);
  }
  if (d[from][m] > maxedit)
    return -1;
  return d[from][m];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", a + 1, b + 1);
    scanf("%d %d %d", &addorremove, &change, &maxedit);
    n = strlen(a + 1);
    m = strlen(b + 1);    
    printf("%d\n", solve());
  }
  return 0;
}
