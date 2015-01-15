#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;
#define MAX 1001
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
vector<pair<pair<double, int>, pair<int,int> > > v;
int main(){
  //freopen("in", "r", stdin);
  int c;
  int n, W;
  double t, U, V;
  UnionFind uf(MAX);
  scanf("%d", &c);
  for(int caso = 1; caso <= c; caso++){
    scanf("%d %lf %d %lf %lf", &n, &t, &W, &U, &V);
    pts.clear();
    for(int i = 0; i < n; i++){
      double x, y;
      scanf("%lf%lf", &x, &y);
      pts.push_back(make_pair(x, y));
    }
    v.clear();
    //0 UTP, 1 fibra optica
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++){
        double distancia = hypot(pts[j].first - pts[i].first, pts[j].second - pts[i].second);
        if(distancia <= t)
          v.push_back(make_pair(make_pair(distancia * U, 0), make_pair(i, j)));
        else
          v.push_back(make_pair(make_pair(distancia * V, 1), make_pair(i, j)));
      }
    sort(v.begin(), v.end());
    uf.reset(n);
    int componentes = n;
    double ans[2] = {0, 0};
    for(int i = 0; i < v.size(); i++){
      int a = v[i].second.first, b = v[i].second.second;
      if(!uf.sameComponent(a, b)){
        uf.Union(a, b);
        componentes--;
        ans[v[i].first.second] += v[i].first.first;
        if(componentes == W || componentes == 1)break;
      }
    }
    printf("Caso #%d: %.3lf %.3lf\n", caso, ans[0], ans[1]);
  }
  return 0;
}
