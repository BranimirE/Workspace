/*
ID: brani.e2
PROG: lgame
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
int val[257];
struct trie {
  map<char, trie> child;
  bool final;
  trie():final(false){}
  void insert(const string &s, int pos = 0) {
    if (pos < s.size()) child[s[pos]].insert(s, pos + 1);
    else                final = true;
  }
  bool count(const string &s, int pos = 0) {
    if (pos == s.size()) return final;    
    if (child.count(s[pos]))
      return child[s[pos]].count(s, pos + 1);
    return false;
  }
} t;
int getPoints(const string &s) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    ans += val[s[i]];
  return ans;
}
string word, tmp;
int n;
int main() {
  memset(val, 0, sizeof(val));
  val['q'] = 7; val['w'] = 6; val['e'] = 1; val['r'] = 2; val['t'] = 2; val['y'] = 5; val['u'] = 4; val['i'] = 1; val['o'] = 3; val['p'] = 5;
  val['a'] = 2; val['s'] = 1; val['d'] = 4; val['f'] = 6; val['g'] = 5; val['h'] = 5; val['j'] = 7; val['k'] = 6; val['l'] = 3;
  val['z'] = 7; val['x'] = 7; val['c'] = 4; val['v'] = 6; val['b'] = 5; val['n'] = 2; val['m'] = 5;
  ifstream dict("lgame.dict");
  while (dict >> tmp && tmp[0] != '.')
    t.insert(tmp);
  freopen("lgame.in", "r", stdin);
  freopen("lgame.out", "w", stdout);
  cin >> word;
  n = word.size();
  int nsubsets = (1 << n);
  int maxpoints = 0;
  vector<pair<string, string> > ans;
  string a, b;
  for (int mask = 0; mask < nsubsets; mask++) {
    if (__builtin_popcount(mask) < 3) continue;
    tmp = "";
    for (int i = 0; i < n; i++)
      if (mask & (1 << i))
	tmp.push_back(word[i]);
    int points = getPoints(tmp);
    if (points < maxpoints) continue;
    sort(tmp.begin(), tmp.end());
    do {
      //Una palabra
      if (t.count(tmp)) {
	if (points == maxpoints)
	  ans.push_back(make_pair(tmp, ""));
	else if (points > maxpoints) {
	  ans.clear();
	  maxpoints = points;
	  ans.push_back(make_pair(tmp, ""));
	}
      }
      //Cortar la palabra
      for (int i = 3; i <= tmp.size(); i++) {
	if (!(tmp.size() - i >= 3)) continue;
	a = tmp.substr(0, i);
	b = tmp.substr(i, tmp.size() - i);
	if (t.count(a) && t.count(b)) {
	  if (points == maxpoints)
	    ans.push_back(make_pair(min(a, b), max(a, b)));
	  else if (points > maxpoints) {
	    ans.clear();
	    maxpoints = points;
	    ans.push_back(make_pair(min(a, b), max(a, b)));
	  }
	}
      }
    } while(next_permutation(tmp.begin(), tmp.end()));
  }
  set<pair<string, string> > bestset(ans.begin(), ans.end());
  set<pair<string, string> >::iterator it;
  printf("%d\n", maxpoints);
  for (it = bestset.begin(); it != bestset.end(); it++) {
    printf("%s", (it->first).c_str());
    if ((it->second).size() > 0)
      printf(" %s", (it->second).c_str());
    printf("\n");
  }
    
  return 0;
}
