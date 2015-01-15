#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int n;
int vec[100010];
int head[100010];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--)
      scanf("%d", &vec[i]);
    head[0] = vec[0];
    int tail = 1;
    for (int i = 1; i < n; i++) {
      int elem = vec[i];
      if (head[0] >= elem) {
	head[0] = elem;
	continue;
      }
      int a = 0, b = tail, m;
      head[tail] = INT_MAX;
      while ((b - a) > 1) {
	m = (b + a) >> 1;
	if (head[m] < elem) a = m;
	else                b = m;
      }
      head[b] = elem;
      if (b == tail)
	tail++;
    }
    printf("%d\n", tail);
  }
  return 0;
}
