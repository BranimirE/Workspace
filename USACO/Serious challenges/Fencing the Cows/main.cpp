/*
ID: brani.e2
PROG: fc
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<double,double> Point;
Point operator - (const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y); }
double cross(const Point &A, const Point &B) {//A y B Vectores
  return A.x * B.y - A.y * B.x; }
double dist(const Point &a, const Point &b) {
  return hypot(a.x - b.x, a.y - b.y);
}
int n;
Point v[10010];
double solve() {
  sort(v, v + n);
  vector<Point> abajo;
  abajo.push_back(v[0]);
  abajo.push_back(v[1]);
  for (int i = 2; i < n; i++) {
    int sz = abajo.size();
    while (sz > 1 && cross(abajo[sz - 1] - abajo[sz - 2], v[i] - abajo[sz - 2]) <= 0.0) {
      abajo.pop_back();
      sz--;
    }
    abajo.push_back(v[i]);
  }
  vector<Point> arriba;
  arriba.push_back(v[n - 1]);
  arriba.push_back(v[n - 2]);
  for (int i = n - 3; i >= 0; i--) {
    int sz = arriba.size();
    while (sz > 1 && cross(arriba[sz - 1] - arriba[sz - 2], v[i] - arriba[sz - 2]) <= 0.0) {
      arriba.pop_back();
      sz--;
    }
    arriba.push_back(v[i]);
  }
  double ans = 0;
  for (int i = 1; i < abajo.size(); i++)
    ans += dist(abajo[i] , abajo[i - 1]);
  for (int i = 1; i < arriba.size(); i++)
    ans += dist(arriba[i], arriba[i - 1]);
  return ans;
}
int main() {
  freopen("fc.in", "r", stdin);
  freopen("fc.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lf %lf", &(v[i].x), &(v[i].y));
  printf("%.2lf\n", solve());
  return 0;
}
