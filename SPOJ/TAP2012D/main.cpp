#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
struct trie {
  map<char, trie> sig;
  int cont[2];
  trie() {cont[0] = cont[1] = 0;}
  void insert(const string &s, int pos, int equipo) {
    if (pos > 0) cont[equipo]++;
    if (pos < sz(s))      
      sig[s[pos]].insert(s, pos + 1, equipo);
  }
  void insert(const string &s, int equipo) {
    trie *cur = this;
    for (int i = 0; i < s.size(); i++) {
      if (!(cur->sig.count(s[i])))
	    cur->sig[s[i]] = trie();
      cur->sig[s[i]].cont[equipo]++;
      cur = &(cur->sig[s[i]]);
    }
  }
  int solve() {
    int ans = min(cont[0], cont[1]);
    map<char, trie>::iterator it;
    for (it = sig.begin(); it != sig.end(); it++)
      ans += (it->second).solve();
    return ans;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  while (cin >> n && n != -1) {
    trie t;
    for (int _ = 0; _ < n; _++) {
      string cad;
      cin >> cad;
      t.insert(cad, 0);
    }
    for (int _ = 0; _ < n; _++) {
      string cad;
      cin >> cad;
      t.insert(cad, 1);
    }
    cout << t.solve() << endl;
  }
  return 0;
}
