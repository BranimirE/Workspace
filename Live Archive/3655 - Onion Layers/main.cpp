#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define Vector Point
const double PI = acos(-1);
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
  double mod() {return hypot(x, y);}
  double angle() {return atan2(y, x);}//En radianes !!!
  void read() {scanf("%d %d", &x, &y);}
  string toString() {
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
  }
};
bool operator <(const Point &a, const Point &b) {
  if(a.x != b.x)
    return a.x < b.x;
  return a.y < b.y;
}
Point operator - (const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y);}
int dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y;}
int cross(const Vector &u, const Vector &v) { return (u.x * v.y) - (u.y * v.x);}
double dist(const Point &a, const Point &b) {return hypot(a.x - b.x, a.y - b.y);}
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

Point base;
bool cmpangle(const Point &a, const Point &b) {
  Point A = a - base, B = b - base;
  double alfa = A.angle(), beta = B.angle();
  if (alfa != beta)
    return alfa < beta;
  return A.mod() < B.mod();
}
void sortbyangle(vector<Point> &p) {
  if (p.empty()) return;
  base = p[0];
  for(Point &e: p)
    if (e.y < base.y)
      base = e;
    else if (e.y == base.y)
      base.x = min(base.x, e.x); 
  sort(p.begin(), p.end(), cmpangle);
}

void reduceConvexHull(vector<Point> & p) {
  int n = p.size();
  if (n < 3) return;
  vector<int> ch(n);
  ch[0] = 0;
  ch[1] = 1;
  int chsize = 2;
  for (int i = 2; i < n; i++) {
    while (chsize >= 2) {
      Point a = p[ ch[chsize - 2] ];
      Point b = p[ ch[chsize - 1] ];
      Point c = p[i];
      if (area(a, b, c) < 0 ) chsize--;
      else break;
    }
    ch[chsize++] = i;
  }
  vector<bool> ans(n, true);
  for (int i = 0; i < chsize; i++)
    ans[ch[i]] = false;
  vector<Point> newp;
  /*
  cout << "Entra:" << endl;
  for (int i = 0; i < n; i++)
    cout << p[i].toString() << " ";
    cout << endl;
  
    cout << "Capa:" << endl;*/
  for (int i = 0; i < n; i++)
    if (ans[i])
      newp.pb(p[i]);
  /*      else
      cout << p[i].toString() << " ";
      cout << endl;*/
  p = newp;
}
void reduceConvexHull2(vector <Point> &P) {

    int n = P.size(),k = 0;
    int H[2*n];
    
    for(int i = 0; i < n; ++i){
        while( k>= 2 && area(P[ H[k-2] ],P[ H[k-1] ], P[i]) < 0) --k;
        H[k++] = i;
    }
    
    for(int i = n - 2, t = k; i >= 0; --i) {
        while(k > t && area(P[ H[k-2] ],P[ H[k-1] ], P[i]) < 0) --k;
        H[k++] = i;
    }
    bool inch[2*n];
    memset(inch, false, sizeof(inch));
    for (int i = 0 ; i < k; i++)
      inch[H[i]] = true;
    vector<Point> newP;
    for (int i = 0; i < n; i++)
      if (!inch[i])
	newP.pb(P[i]);
    P = newP;

}
int solve(vector<Point> &pts) {

  int ans = 0;
  //  sort(pts.begin(),pts.end());
  while (!pts.empty()) {

    assert(pts.size() >= 3);
    //    cout << pts.size() << endl;
    ans++;
    sortbyangle(pts);
    reduceConvexHull(pts);
  }
  return ans;
}
int main() {
  int n;
  while (scanf("%d", &n) && n) {
    vector<Point> pts(n);
    for (Point &e: pts)
      e.read();
    printf((solve(pts)&1)?"Take this onion to the lab!\n":"Do not take this onion to the lab!\n");
  }
  return 0;
}
