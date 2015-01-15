#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
char cad[30];
char ans[30];
bool match;
struct trie {
  map<char, trie> sig;
  bool final;
  trie() {final = false;}
  void insert(const string& s, int pos = 0) {
    if (pos < sz(s)) sig[s[pos]].insert(s, pos + 1);
    else             final = true;
  }
  bool solve(const string& s, int pos = 0) {
    if (pos < sz(s)) {
      if (!sig.count(s[pos]))
	return false;
      ans[pos] = s[pos];
      return sig[s[pos]].solve(s, pos + 1);
    } else {
      if (final && pos > sz(s)) {
	ans[pos] = '\0';
	printf("%s\n", ans);
      }
      map<char, trie>::iterator it;
      for (it = sig.begin(); it != sig.end(); it++) {
	ans[pos] = it->first;
	(it->second).solve(s, pos + 1);
      }
      return sig.size();;
    }
  }
} t;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", cad);
    t.insert(string(cad, cad + strlen(cad)));
  }
  scanf("%d", &n);
  for (int caso = 1; caso <= n; caso++){
    printf("Case #%d:\n", caso);
    scanf("%s", cad);
    if (!t.solve(string(cad, cad + strlen(cad))))
      printf("No match.\n");
  }
  return 0;
}
