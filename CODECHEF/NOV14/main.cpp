#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int Number;
int x;
Number k;
double solve(double width, Number step) {
  Number div = 0;
  
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %lld", &x, &k);
    printf("%lf", solve(x, k));
  }
  return 0;
}
