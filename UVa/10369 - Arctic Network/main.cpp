#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 505

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
vector<pair<double, double> > pts;
vector<pair<double, pair<int, int> > > g;
int main(){
  //freopen("in", "r", stdin);
  int t, sa, n;
  scanf("%d", &t);
  UnionFind uf(MAX - 1);
  while(t--){
    scanf("%d%d", &sa, &n);
    pts.clear();
    for(int i = 0; i < n; i++){
      double x,y;
      scanf("%lf%lf", &x, &y);
      pts.push_back(make_pair(x,y));
    }
    g.clear();
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        g.push_back(make_pair(hypot(pts[i].first-pts[j].first, pts[i].second-pts[j].second), make_pair(i, j)));
    sort(g.begin(), g.end());
    uf.reset(n);
    int comp = n;
    double ans = 0;
    for(int i = 0; i < g.size(); i++){
      int a = g[i].second.first, b = g[i].second.second;
      double p = g[i].first;
      if(!uf.sameComponent(a, b)){
        uf.Union(a, b);
        comp--;
        ans = p;
        if(comp == sa)
          break;
      }
    }
    printf("%.2f\n",ans );
  }
  return 0;
}
