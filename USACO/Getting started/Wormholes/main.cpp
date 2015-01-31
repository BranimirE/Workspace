/*
ID: brani.e2
PROG: wormhole
LANG: C++
 */
#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
set<int> xx, yy;
vector<int> ix;
vector<int> iy;

int n;
int x[20];
int y[20];
int match[20];
int cnt = 0;
int hole[24][12];
int maxX;
bool vis[30][30];
bool dfs(int X, int Y) {
  if (X > maxX) return false;//Logre salir :D
  if (vis[X][Y]) return true;
  vis[X][Y] = true;
  X++;//Avanzo
  if (hole[X][Y] == -1)//No hole
    return dfs(X, Y);
  else {
    int i = hole[X][Y];
    return dfs(x[i] + 1, y[i]);
  }
}
bool check() {
  memset(hole, -1, sizeof(hole));
  forn (i, n)
    hole[x[i]][y[i]] = match[i];
  maxX = (sz(ix) - 1) * 2 + 1;
  int maxY = sz(iy) - 1;
  for (int X = 0; X <= maxX; X++)
    for (int Y = 0; Y <= maxY; Y++) {
      if (hole[X][Y] == -1) {
	memset(vis, false, sizeof(vis));	
	if (dfs(X, Y))
	  return true;
      }
    }
  return false;
}
void generate(int elemts) {
  if (elemts == 0) {
    if (check())
      cnt++;
    return;
  }
  forn (i, n)
    if (match[i] == -1) {
      for (int j = i + 1; j < n; j++)
	if (match[j] == -1) {
	  match[i] = j;
	  match[j] = i;
	  generate(elemts - 2);
	  match[i] = match[j] = -1;
	}
      return;
    }
}
int main() {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);
  scanf("%d", &n);
  forn (i, n) {
    scanf("%d %d", x + i, y + i);
    xx.insert(x[i]);
    yy.insert(y[i]);
  }
  ix = vector<int>(all(xx));
  iy = vector<int>(all(yy));
  forn (i, n) {
    x[i] = (lower_bound(all(ix), x[i]) - ix.begin()) * 2 + 1;
    y[i] = lower_bound(all(iy), y[i]) - iy.begin();
  }
  memset(match, -1, sizeof(match));
  cnt = 0;
  generate(n);
  printf("%d\n", cnt);
  return 0;
}
