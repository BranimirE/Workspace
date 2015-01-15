#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define Vector Point
typedef long long int Number;
struct Point{
  Number x, y;
  Point(Number _x = 0, Number _y = 0):x(_x), y(_y) {}
  void read() {scanf("%lld %lld", &x, &y);}
};
Number cross(const Vector &u, const Vector &v) {return (u.x * v.y - u.y * v.x);}
Point operator - (const Point &a, const Point &b) {return Point(a.x - b.x, a.y - b.y);}
bool isConvex(const vector<Point> &p) {
  int n = sz(p);
  int pos = 0, neg = 0;
  for (int i = 0; i < n; i++) {
    int prev = (i + n - 1) % n;
    int next = (i + n + 1) % n;
    Number pc = cross(p[prev] - p[i], p[next] - p[i]);
    if (pc > 0) pos++;
    if (pc < 0) neg++;
  }
  return (pos == 0) || (neg == 0);
}
int main() {
  int n;
  while (scanf("%d", &n) && n) {
    vector<Point> polygon(n);
    for(Point &e: polygon)
      e.read();
    printf(isConvex(polygon)?"No\n":"Yes\n");
  }
  return 0;
}
