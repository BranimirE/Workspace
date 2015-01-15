#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
int k;
char goodorbad[30];
char c[1510];
int v[1500];
int ans;
struct trie {
  map<char, trie> sig;
  void insert(const string &s, int pos, int badletters) {
    if (badletters < 0)return;
    if (pos < sz(s)) {
      int totalbad = badletters - (goodorbad[s[pos] - 'a']=='0');
      if (!sig.count(s[pos]) && totalbad >= 0) ans++;
      sig[ s[pos] ].insert(s, pos + 1, totalbad);
    }
  }
} s;
int main() {
  scanf("%s %s %d", c, goodorbad, &k);
  int n = strlen(c);
  ans = 0;
  for (int i = 0; i < n; i++)
    s.insert(string(c + i, c + n), 0, k);
  printf("%d\n", ans);
  return 0;
}
