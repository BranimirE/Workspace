/*
ID: brani.e2
PROG: frameup
LANG: C++11
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
struct frame {
  int imin, jmin, imax, jmax;
  frame() {
    imin = jmin = INT_MAX;
    imax = jmax = INT_MIN;
  }
} frames[40];

bool in_set[40];
int n, m;
char v[40][40];
bool g[30][30];
int cnt;
void pre() {
  memset(g, false, sizeof(g));
  cnt = 0;
  for (int fr = 0; fr < 26; fr++)
    if (in_set[fr]) {
      cnt++;
      int i = frames[fr].imin;
      int j = frames[fr].jmin;
      int ii = frames[fr].imax;
      int jj = frames[fr].jmax;
      char car = fr + 'A';
      for (int k = j; k <= jj; k++) {
	if (v[i][k] != car)
	  g[fr][v[i][k] - 'A'] = true;
	if (v[ii][k] != car)
	  g[fr][v[ii][k] - 'A'] = true;
      }
      for (int k = i; k <= ii; k++) {
	if (v[k][j] != car)
	  g[fr][v[k][j] - 'A'] = true;
	if (v[k][jj] != car)
	  g[fr][v[k][jj] - 'A'] = true;
      }
    }
}
bool vis[31];
int degree[31];
char cad[30];
void solve(int pos = 0) {
  if (pos == cnt) {
    cad[pos] = '\0';
    printf("%s\n", cad);
    return;
  }
  for (int i = 0; i < 26; i++)
    if (in_set[i] && degree[i] == 0 && !vis[i]) {
      cad[pos] = 'A' + i;
      vis[i] = true;
      for (int j = 0; j < 26; j++)
	if (g[i][j])
	  degree[j]--;
      solve(pos + 1);
      for (int j = 0; j < 26; j++)
	if (g[i][j])
	  degree[j]++;
      vis[i] = false;
    }
}
int main() {
  freopen("frameup.in", "r", stdin);
  freopen("frameup.out", "w", stdout);
  memset(in_set, false, sizeof(in_set));
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%s", v[i]);
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') continue;
      int e = v[i][j] - 'A';
      frames[e].imin = min(frames[e].imin, i);
      frames[e].jmin = min(frames[e].jmin, j);
      frames[e].imax = max(frames[e].imax, i);
      frames[e].jmax = max(frames[e].jmax, j);
      in_set[e] = true;
    }
  }
  pre();
  memset(degree, 0, sizeof(degree));
  for (int i = 0; i < 26; i++)
    if (in_set[i])
      for (int j = 0; j < 26; j++)
	if (g[i][j])
	  degree[j]++;
  solve(0);
  return 0;
}
