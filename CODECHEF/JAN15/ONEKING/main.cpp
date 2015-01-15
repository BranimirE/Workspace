#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define ini first
#define fin second
pair<int,int> a[100010];
int n;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	forn (i, n)
	    scanf("%d %d", &a[i].ini, &a[i].fin);
	sort(a, a + n);
	int ans = (n != 0);
	int maxfin = a[0].fin;
	forn (i, n) {
	    if (a[i].ini <= maxfin) {
		maxfin = min(maxfin, a[i].fin);
	    } else {
		ans++;
		maxfin = a[i].fin;
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
