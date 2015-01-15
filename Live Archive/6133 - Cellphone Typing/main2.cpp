#include <bits/stdc++.h>

using namespace std;
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

struct trie {
  map<char, trie> sig;
  bool final = false;
  void insert(const string &s, int pos = 0) {
    if (pos < sz(s)) sig[ s[pos] ].insert(s, pos + 1);
    else final = true;
  }
  int solve(int acu = 0, bool isroot = true) {
    int ans = 0;
    if (final) ans = acu;
    if (sz(sig) > 1 || isroot || final) acu++;
    for (auto &e: sig) ans += e.second.solve(acu, false);
    return ans;
  }
};
char buf[90];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    trie t;
    string s;
    forn (_, n) {
      scanf("%s", buf);
      s = string(buf);
      t.insert(s);
    }
    printf("%.2lf\n", double(t.solve()) / n);
  }
  return 0;
}
