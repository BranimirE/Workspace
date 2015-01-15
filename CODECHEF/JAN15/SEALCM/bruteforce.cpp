#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int lcm (int a, int b) {
    return a / __gcd(a, b) * b;
}
int main() {
    int ans = 0;
    for (int a = 1; a <= 5; a++)
	for (int b = 1; b <= 5; b++) {
	    int l = lcm(a, b);
	    if (l%4 == 0)
		ans++;
	}
    cout << ans << endl;
    return 0;
}
