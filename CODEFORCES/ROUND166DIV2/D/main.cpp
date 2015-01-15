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
  int final;
  trie() {final = 0;};
  void insert(const string &s, int pos = 0) {
    if (pos < sz(s))
      sig[ s[pos] ].insert(s, pos + 1);
    else
      if (!final) {
	final = true;
	ans++;
      }
  }
} s;
int main() {
  scanf("%s %s %d", c + 1, goodorbad, &k);
  v[0] = 0;
  int n = strlen(c + 1);
  for (int i = 1; i <= n; i++) {
    v[i] = v[i - 1];
    if (goodorbad[c[i] - 'a'] == '0')
      v[i]++;
  }
  ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n && (v[j] - v[i - 1]) <= k; j++)
      s.insert(string(c + i, c + j + 1));

  printf("%d\n", ans);
  return 0;
}
