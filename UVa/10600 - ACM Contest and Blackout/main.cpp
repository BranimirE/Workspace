#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

#define MAX 102

using namespace std;
struct UnionFind {
  int p[MAX];
  int r[MAX];
  int n;
  UnionFind(int _n) {
    reset(_n);
  }
  void reset(int N) {
    n = N;
    for(int i = 0 ; i <= n ; ++i )
      p[i] = i, r[i] = 0;
  }
  int Find(int x) {
    return (p[x]==x?x:p[x]=Find(p[x]));
  }
  bool sameComponent(int x, int y) {
    return Find(x) == Find(y);
  }
  void Union(int x, int y) {
    int xRoot = Find(x);
    int yRoot = Find(y);
    if(r[xRoot] > r[yRoot])
      p[yRoot] = xRoot;
    else {
      p[xRoot] = yRoot;
      if(r[xRoot] == r[yRoot])
        r[yRoot]++;
    }
  }
};
vector<pair<long long int, pair<int, int> > > g;
vector<int> mst;
UnionFind uf(MAX - 1);
int t, n, m, u, v;
long long int p;
long long int solve(int ign, bool guardar) {
  long long int ans = 0;
  uf.reset(n);
  int comp = n;
  for(int i = 0; i < g.size(); i++) {
    if(i == ign)continue;
    int a = g[i].second.first, b = g[i].second.second;
    long long int p = g[i].first;
    if(!uf.sameComponent(a, b)) {
      uf.Union(a, b);
      ans += p;
      if(guardar) mst.push_back(i);
      comp--;
      if(comp == 1)break;
    }
  }
  if(comp != 1)return LLONG_MAX;
  return ans;
}
int main() {
  freopen("in", "r", stdin);
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    g.clear();
    while(m--) {
      scanf("%d%d%lld", &u, &v, &p);
      g.push_back(make_pair(p, make_pair(u,v)));
    }
    sort(g.begin(), g.end());
    mst.clear();
    long long int first = solve(-1, true), second = LLONG_MAX;
    for(int i = 0; i < mst.size(); i++)
      second = min(second, solve(mst[i], false));
    printf("%lld %lld\n", first, second);
  }
  return 0;
}
