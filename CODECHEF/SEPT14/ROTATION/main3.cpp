#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN 100010
int v[MAXN], cp[MAXN];
int n;
char buf[20];
int main() {
  int m;
  scanf("%d %d", &n, &m);
  forn (i, n)
    scanf("%d", &v[i]);
  gets(buf);
  int offset = 0;
  char op;
  int pos;
  while (m--) {
    gets(buf);
    sscanf(buf, "%c %d", &op, &pos);
    if (op == 'R') {
      pos = offset + (pos - 1);
      if (pos >= n) pos -= n;
      printf("%d\n", v[pos]);
    }else {
      if (op == 'C') {
	offset += pos;
	if (offset >= n) offset -= n;
      }else {
	offset -= pos;
	if (offset < 0) offset += n;
      }
    }
  }
  return 0;
}
