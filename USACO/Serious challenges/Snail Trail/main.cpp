/*
ID: brani.e2
PROG: snail
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
int n;
char mapa[130][130];
int dx[4] = {0, 1, 0,-1};
int dy[4] = {1, 0,-1, 0};
int solve(int i, int j, int dir) {
  if (mapa[i][j] != '.')
    return 0;
  int ans = 1; // current position
  mapa[i][j] = 'o';
  int ii = i + dx[dir];
  int jj = j + dy[dir];
  if (mapa[ii][jj] != '#')
    ans = 1 + solve(ii, jj, dir);
  else {
    int dir1 = dir + 1, dir2 = dir - 1;
    if (dir1 == 4) dir1 = 0;
    if (dir2 == -1) dir2 = 3;
    ans = 1 + max(solve(i + dx[dir1], j + dy[dir1], dir1),
		  solve(i + dx[dir2], j + dy[dir2], dir2));
  }
  mapa[i][j] = '.';
  return ans;
}
int main() {
  freopen("snail.in", "r", stdin);
  freopen("snail.out", "w", stdout);
  int tmp;
  scanf("%d %d\n", &n, &tmp);
  memset(mapa, '#', sizeof(mapa));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      mapa[i][j] = '.';
  while (tmp--) {
    char col;
    int row;
    scanf("%c%d\n", &col, &row);
    mapa[row][col - 'A' + 1] = '#';
  }
  printf("%d\n", max(solve(1, 1, 0), solve(1, 1, 1)));
  return 0;
}
