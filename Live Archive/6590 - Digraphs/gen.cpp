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
bool g[30][30];
int main() {
  memset(g, 0, sizeof(g));

  for (int v = 1; v < 26; v++) {
    int u = v - 1;
    g[u][v] = 1;
  }
  int cnt = 0;
  forn (a, 26)
    forn (b, 26)
    if (!g[a][b]) {
      printf("%c%c\n", 'a' + a, 'a' + b);
      cnt++;
    }
  cout << cnt << endl;
  return 0;
}
