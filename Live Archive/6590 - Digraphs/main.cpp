#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
const int white = -1, gray = 0, black = 1;
bool g[30][30];
char buff[10];
int color[30];
int padre[30];
vector<char> ans;
vector<int> top_sort;
bool ciclo(int u) {
  color[u] = gray;
  forn (v, 26)
    if (g[u][v]) {
      if (color[v] == white) {
        padre[v] = u;
        if (ciclo(v))
          return true;
      } else if (color[v] == gray) {//ciclo
        ans.clear();
        int cur = u;
        while (cur != padre[v]) {
          ans.pb('a' + cur);
          cur = padre[cur];
        }
        reverse(all(ans));
        return true;
      }
    }
  color[u] = black;
  top_sort.pb(u);
  return false;
}
int max_path[30];
int sig[30];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    forn (i, 26)
      fill(g[i], g[i] + 26, true);

    int np;
    scanf("%d", &np);
    while (np--) {
      scanf("%s", buff);
      g[buff[0] - 'a'][buff[1] - 'a'] = false;
    }

    memset(padre, -1, sizeof(padre));
    memset(color, white, sizeof(color));
    bool ok = false;
    top_sort.clear();
    forn (v, 26)
      if (color[v] == white) {
        if (ciclo(v)) {
          ok = true;
          break;
        }
      }
    if (ok) {//Ciclo!!!
      int n = sz(ans);
      forn (i, 20) {
        forn (j, 20)
          printf("%c", ans[(i + j) % n]);
        printf("\n");
      }
    } else {//No ciclo!!! :-(
      int ini = -1;
      assert(sz(top_sort) == 26);
      forn (i, 26) {
        int u = top_sort[i];
        sig[u] = -1;
        max_path[u] = 1;
        forn (v, 26)
          if (g[u][v]) {
            if (1 + max_path[v] > max_path[u]) {
              max_path[u] = 1 + max_path[v];
              sig[u] = v;
            }
          }
        if (ini == -1 || max_path[u] >= max_path[ini])
          ini = u;
      }
      ans.clear();
      while (ini != -1) {
        ans.pb('a' + ini);
        ini = sig[ini];
      }
      
      int n = sz(ans);
      if (!(n & 1))//par
        n--;//debe ser impar
      
      int lado = (n + 1) / 2;
      forn (i, lado) {
        forn (j, lado)
          printf("%c", ans[(i + j)]);
        printf("\n");
      }
    }
  }
  return 0;
}
