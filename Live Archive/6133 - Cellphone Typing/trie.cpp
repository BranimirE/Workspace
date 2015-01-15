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
  void insert(char *s) {
    if (*s != '\0') sig[*s].insert(s + 1);
    else final = true;
  }
  void insert(const string &s) {
    trie *cur = this;
    for (int i = 0; i < s.size(); i++)
      cur = &(cur->sig[s[i]]);
    (cur->final) = true;
  }
  void print(string s = "") {
    if (final)cout << "\"" << s << "\"" << endl;
    for (auto &e: sig)
      e.second.print(s + e.first);
  }
};

int main() {
  
  return 0;
}
