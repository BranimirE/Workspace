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

Number t, n, k, ans, d, g;
Number tiempo[100010];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
	cin >> n >> k,
	ans = 0;
	forn (i, n) cin >> tiempo[i];
	forn (i, n) {
	    cin >> g;
	    ans = max(ans, (k / tiempo[i]) * g);
	}
	cout << ans << endl;
    }
    return 0;
}
