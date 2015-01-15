#include <cstdio>

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
  void insert(char *s) {
    if (*s != '\0') {
      if (sig[*s - 'a'] == NULL) {
	sig[*s - 'a'] = new trie();
	size++;
      }
      sig[ *s - 'a' ]->insert(s + 1);
    }else final = true;
  }  
  int solve(int acu = 0, bool isroot = true) {
    int ans = 0;
    if (final) ans = acu;
    if (size > 1 || isroot || final) acu++;
    forn (i, 26) {
      trie* &e = sig[i];
      if (e != NULL)
	ans += e->solve(acu, false);
    }
    return ans;
  }
};
char buf[90];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    trie t;
    forn (_, n) {
      scanf("%s", buf);
      t.insert(buf);
    }
    printf("%.2lf\n", double(t.solve()) / n);
  }
  return 0;
}
