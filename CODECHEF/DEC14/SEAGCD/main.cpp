#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
int n, m;
int v[11];
int cnt[11];
void solve(int i) {
  if (i == n) {
    int gcd = v[0];
    for (int j = 1; j < n; j++)
      gcd = __gcd(gcd, v[j]);
    cnt[gcd]++;
    return;
  }
  for (int num = 1; num <= m; num++) {
    v[i] = num;
    solve(i + 1);
  }
}
int main() {
  int t;
  int l, r;
  cin >> t;
  while (t--) {
    cin >> n >> m;// >> l >> r;
    memset(cnt, 0, sizeof(cnt));
    solve(0);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      cout << "cnt[" << i << "] = " << cnt[i] << endl;
    }
    cout << string(20, '-') << endl;

  }
  return 0;
}
