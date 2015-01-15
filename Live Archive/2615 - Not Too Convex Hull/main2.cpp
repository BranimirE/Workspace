#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define Vector Point
#define EPS 1e-8
#define INF 1e18
const double PI = acos(double(-1));
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
  double angle() {return atan2(double(y), double(x));}//En radianes !!!
  void read() {scanf("%d %d", &x, &y);}
};
Point operator - (const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y);}
int dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y;}
int cross(const Vector &u, const Vector &v) { return (u.x * v.y) - (u.y * v.x);}

double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
Point base;
bool cmpangle(const Point &a, const Point &b) {
  Point A = a - base, B = b - base;
  return A.angle() < B.angle();
}
void sortbyangle(vector<Point> &p) {
  if (p.empty()) return;
  base = p[0];
  sort(p.begin() + 1, p.end(), cmpangle);
}

vector<pair<int, double> > g[213];
double dp[213][53];
double solve(int pos, int bands, int fin) {
  //  cout << "solve(" << pos << ", " << bands << ", " << fin << ")" << endl;
  if (pos > fin) {
    if (bands == 0)
      return 0.0;
    else
      return INF;
  }
  double &ans = dp[pos][bands];
  if (ans > EPS) return ans;
  ans = INF;
  for (int i = 0; i < g[pos].size(); i++) {
    int sig = g[pos][i].first;
    double xarea = g[pos][i].second;
    if (sig > fin) break;
    ans = min(ans, xarea + solve(sig + 1, bands - 1, fin));
  }
  return ans;
}
int main() {
  int n, b;
  while (scanf("%d%d", &b, &n) && n+b) {
    vector<Point> pts(n);
    for (int i = 0; i < n; i++)
      pts[i].read();
    sortbyangle(pts);
    /*    for (int i = 0; i < pts.size(); i++) {
      cout << i << " : " << pts[i].toString() << endl;
      }*/

    n--; 
    for (int i = 1; i <= n; i++) {
      g[i].clear();

      for (int j = i + 1; j < pts.size(); j++) {

	if (area(pts[0], pts[i], pts[j]) <= 0) break;
	
	vector<int> ch;
	ch.pb(0);
	ch.pb(i);
	ch.pb(i + 1);
	for (int k = i + 2; k <= j; k++) {
	  while (sz(ch) >= 3 && area(pts[ch[sz(ch) - 2]], pts[ch[sz(ch) - 1]], pts[k]) <= 0)
	    ch.pop_back();
	  ch.pb(k);
	}
	/*
	for (int k = 0; k < ch.size(); k++)
	  cout << ch[k] << ", ";
	cout << endl;
	//	DBG(ch.size());
	*/
	double myarea = 0;
	for (int k = 1; k < sz(ch); k++)
	  myarea += area(pts[0], pts[ch[k - 1]], pts[ch[k]]);
	assert(myarea > 0);

	g[i].pb(mp(j, myarea / double(2.0)));
      }
      pts.pb(pts[i]);
    }

    /*
    for (int i = 1; i <= n; i++) {
      cout << i << " : ";
      for (int j = 0; j < g[i].size(); j++)
	cout << "(" << g[i][j].first << ", " << g[i][j].second << ") ";
      cout << endl;
    }
    //    break;
    cout << endl;
    */
    
    double ans = INF;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2 * n; j++)
	fill(dp[j], dp[j] + b + 1, 0);
      
      ans = min(ans, solve(i, b, i + n - 1));
      
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
