#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
int n, a[10010];
bool solve(int sum) {
    if (sum < 100) return false;
    if (sum == 100) return true;
    return (sum - 100) < n;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	int sum = 0, N = 0;
	forn (i, n) {
	    scanf("%d", a + i);
	    if (a[i] > 0) {
		sum += a[i];
		N++;
	    }
	}
	n = N;
	printf(solve(sum)?"YES\n":"NO\n");
    }
    return 0;
}
