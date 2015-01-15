#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN 100000
int c[MAXN + 10];
int tree[4 * MAXN + 40];
int newpos = 0;
int N;
void init(int node,int a,int b) {
    if(a == b) {
        tree[node] = c[a];
        return ;
    }
    init(2 * node + 1, a        , (a+b)/2);
    init(2 * node + 2, (a+b)/2+1, b      );
    tree[node] = __gcd(tree[2*node+1], tree[2*node+2]);
}
void update(int node,int a,int b,int p,int val) {
    if(p<a || b<p)return;
    if(a==b) {
        tree[node]=val;
        return ;
    }
    update(2*node+1,a,(a+b)/2,p,val);
    update(2*node+2,(a+b)/2+1,b,p,val);
    tree[node] = __gcd(tree[2*node+1],tree[2*node+2]);
}
vector<int> posiciones[10010];
int CON() {
  return tree[0];
}
void REM(int num) {
  assert(posiciones[num].size() > 0);
  int pos = posiciones[num].back();
  posiciones[num].pop_back();
  update(0, 0, N - 1, pos, 0);
}
void ADD(int num) {
  int pos = newpos++;
  update(0, 0, N - 1, pos, num);
  posiciones[num].pb(pos);
}
// <(0(add), 1(rem), 2(con)) , (num)>
pair<int, int> queries[MAXN + 10];
char buf[10];
int main() {
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    int adds = 0;
    int num,  maxnum = 0;
    scanf("%d", &n);
    forn (i, n) {
      scanf("%s", buf);
      if (buf[0] == 'U') {
	scanf("%s %d", buf, &num);
	maxnum = max(maxnum, num);
	if (buf[0] == 'A') {
	  queries[i] = mp(0, num);
	  adds++;
	}
	else
	  queries[i] = mp(1, num);
      } else {
	queries[i] = mp(2, 0);
      }
    }
    for (int i = 1; i <= maxnum; i++)
      posiciones[i].clear();
    newpos = 0;
    N = adds;
    fill (c, c + N, 0);
    init(0, 0, N - 1);
    forn (i, n) {
      if (queries[i].first == 0)
	ADD(queries[i].second);
      if (queries[i].first == 1)
	REM(queries[i].second);
      if (queries[i].first == 2)
	printf("%d\n", CON());
    }
    
  }
  return 0;
}
