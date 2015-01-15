#include <bits/stdc++.h>

using namespace std;
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

struct trie {
  bool final;
  trie* sig[26];
  int size;
  trie() {
    final = false;
    size = 0;
    forn (i, 26) sig[i] = NULL;
  }
  
  void insert(const string &s, int pos = 0) {
    if (pos < sz(s)) {
      if (sig[s[pos] - 'a'] == NULL) {
	sig[s[pos] - 'a'] = new trie();
	size++;
      }
      sig[ s[pos] - 'a' ]->insert(s, pos + 1);      
    }else final = true;
  }
  
  int solve(int acu = 0, bool isroot = true) {
    int ans = 0;
    if (final) ans = acu;
    if (size > 1 || isroot || final) acu++;
    for (auto &e: sig)
      if (e != NULL)
	ans += e->solve(acu, false);
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
