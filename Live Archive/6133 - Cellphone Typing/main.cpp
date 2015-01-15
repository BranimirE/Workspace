#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
struct trie {
  map<char, trie> sig;
  bool final;
  trie() {final = false;}
  void insert(const string &s, int pos = 0) {
    if (pos < sz(s)) sig[ s[pos] ].insert(s, pos + 1);
    else final = true;
  }
  int solve(int acu = 0, bool isroot = true) {
    int ans = 0;
    if (final) ans = acu;
    if (sz(sig) > 1 || isroot || final) acu++;
    for (auto &e: sig)
      ans += e.second.solve(acu, false);
    return ans;
  }
  void print(string s = "") {
    if (final)cout << "\"" << s << "\"" << endl;
    for (auto &e: sig)
      e.second.print(s + e.first);
  }
};
char buf[90];
int main() {
  //  ios_base::sync_with_stdio(false);
  int n;
  while (scanf("%d", &n) != EOF) {
    trie t;
    string s;
    forn (_, n) {
      scanf("%s", buf);
      s = string(buf);
      t.insert(s);
    }
    //    t.print();
    printf("%.2lf\n", double(t.solve()) / n);
  }
  return 0;
}
