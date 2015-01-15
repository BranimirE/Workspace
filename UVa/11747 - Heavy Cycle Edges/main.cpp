#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX 1005

using namespace std;
struct UnionFind {
  int p[MAX];
  int r[MAX];
  int n;
  UnionFind(int _n) {
    reset(_n);
  }
  void reset(int N){
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
int main(){
  freopen("in", "r", stdin);
  int n, m, u, v, p;
  UnionFind uf(MAX - 1);
  vector<pair<int,pair<int,int> > > g;
  while(scanf("%d%d", &n, &m) and !(!n and !m)){
    uf.reset(n);
    g.clear();
    while(m--){
      scanf("%d%d%d", &u, &v, &p);
      g.push_back(make_pair(p, make_pair(u,v)));
    }
    sort(g.begin(), g.end());
    bool sw = true;
    for(int i = 0; i < g.size(); i++){
      u = g[i].second.first; v = g[i].second.second;
      if(!uf.sameComponent(u, v))
        uf.Union(u,v);
      else{
        printf("%s%d", sw?"":" ", g[i].first);
        sw = false;
      }
    }
    if(sw)
      printf("forest");
    puts("");
  }
  return 0;
}
