#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define EPS (1e-9)
#define Vector Point
typedef long long int Number;
struct Point {
  Number x, y;
  Point() {
    x = y = 0;
  }
  Point(Number _x, Number _y) {
    x = _x;
    y = _y;
  }
  Point ort() {
    return Point(-y, x);
  }
  string toString() {
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
  }
};
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, Number k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, Number k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b) {
  return a.x == b.x && a.y == b.y;
}
bool operator !=(const Point &a, const Point &b) {
    return !(a==b);
}
bool operator <(const Point &a, const Point &b) {
  if (a.x != b.x)
    return a.x < b.x;
  return a.y < b.y;
}
Point nullpoint(INT_MAX, INT_MAX);
int n;
Point p[2010];
bool exist(const Point &obj) {
  return binary_search(p + 1, p + 1 + n, obj);
}

int solve() {
  int ans = 3;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      Vector ORT = (p[j] - p[i]).ort();
      Point A = p[i] + ORT;
      Point B = p[j] + ORT;
      int need = 0;
      if (!exist(A))need++;
      if (!exist(B))need++;
      ans = min(ans, need);
      A = p[i] - ORT;
      B = p[j] - ORT;
      need = 0;
      if (!exist(A))need++;
      if (!exist(B))need++;
      ans = min(ans, need);

      //      cout << "p[i] :" << p[i].x << ", " << p[i].y << " p[j] : " << p[j].x << ", " << p[j].y << endl;
      A = p[j] - p[i] + ORT;
      B = p[j] - p[i] - ORT;
      //      cerr << "ORT: " << ORT.toString() << endl;
      if (A.x % 2LL == 0LL && A.y % 2LL == 0) A = p[i] + (A / 2LL);
      else A = nullpoint;
      if (B.x % 2LL == 0LL && B.y % 2LL == 0) B = p[i] + (B / 2LL);
      else B = nullpoint;
      need = 0;
      //      cout << "\t A: " << A.x << ", " << A.y << "  B: " << B.x << ", " << B.y << endl;
      if (!exist(A))need++;
      if (!exist(B))need++;
      ans = min(ans, need);
      if (ans == 0) return ans;
    }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i].x >> p[i].y;
  sort(p + 1, p + n + 1);
  int ans = 4;
  if (n) 
    ans = solve();
  cout << ans << endl;
  return 0;
}
