#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int n, N;
string ini, fin;

int parent[16773121][25];
pair<int,int> parse(const string &s) {
  int mask = 0, pos = 0;
  int bit = 1;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == ' ') {
      pos = i;
      continue;
    }
    if (s[i] == 'B')
      mask |= bit;
    bit <<= 1;
  }
  return mp(mask, pos);
}

void run() {
  pair<int, int> tmp;
  queue<pair<string, int> > q;
  q.push(mp(ini, n));
  memset(parent, -1, sizeof(parent));
  
  string u, v; int pos;
  tmp = parse(ini);
  parent[tmp.first][tmp.second] = -2;
  while (!q.empty()) {
    tie(u, pos) = q.front();
    q.pop();
    if ((pos - 1) >= 0) {
      v = u;
      swap(v[pos-1], v[pos]);
      tmp = parse(v);
      if (parent[tmp.first][tmp.second] == -1) {
        parent[tmp.first][tmp.second] = pos;
	if (v == fin) return;
	q.push(mp(v, pos - 1));
      }
    }

    if ((pos - 2) >= 0 && u[pos - 1] != u[pos - 2]) {
      v = u;
      swap(v[pos-2], v[pos]);
      tmp = parse(v);
      if (parent[tmp.first][tmp.second] == -1) {
        parent[tmp.first][tmp.second] = pos;
	if (v == fin) return;
	q.push(mp(v, pos - 2));
      }
    }


    if ((pos + 1) < N) {
      v = u;
      swap(v[pos], v[pos + 1]);
      tmp = parse(v);
      if (parent[tmp.first][tmp.second] == -1) {
        parent[tmp.first][tmp.second] = pos;
	if (v == fin) return;
	q.push(mp(v, pos + 1));
      }
    }

    if ((pos + 2) < N && u[pos + 1] != u[pos + 2]) {
      v = u;
      swap(v[pos], v[pos + 2]);
      tmp = parse(v);
      if (parent[tmp.first][tmp.second] == -1) {
        parent[tmp.first][tmp.second] = pos;
	if (v == fin) return;
	q.push(mp(v, pos + 2));
      }
    }    
  }
  }
int main() {
  
  scanf("%d", &n);
  ini = string(n, 'W') + string(" ") + string(n, 'B');
  fin = string(n, 'B') + string(" ") + string(n, 'W');
  N = sz(ini);

  run();

  vector<int> ans;
  int pos;
  int espacio = n;
  ans.pb(n + 1);
  pair<int,int> tmp = parse(fin);
  while ((pos = parent[tmp.first][tmp.second]) != -2) {
    ans.pb(pos + 1);
    swap(fin[espacio], fin[pos]);
    espacio = pos;
    tmp = parse(fin);
  }
  for (int i = ans.size() - 2; i >= 0; i--)
    cout << ans[i] << ",";
  cout << endl;

  return 0;
}
