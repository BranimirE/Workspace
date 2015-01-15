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
char c[1000010];
Number a[3], ans, n, sum;
void add () {
    forn (i, 3) {
	n = a[i];
	a[i] = 0;
	if (!i) n++;
	ans += n * (n - 1LL) / 2LL;
    }
    sum = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    while (gets(c)) {
	sum = ans = 0;
	memset(a, 0, sizeof(a));
	for (char *e = c; *e; e++)
	    if (!isdigit(*e))
		add();
	    else {
		sum = (sum + *e - '0') % 3;
		a[sum]++;
	    }
	add();
	printf("%lld\n", ans);
    }
    return 0;
}
