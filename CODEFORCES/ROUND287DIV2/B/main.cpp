#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    int r, x, y, i, j;
    cin >> r >> x >> y >> i >> j;
    int ans = ceil(hypot(x - i, y - j) / double(2 * r));
    cout << ans << endl;
    return 0;
}
