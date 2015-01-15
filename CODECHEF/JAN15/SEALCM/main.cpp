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
//const Number MOD = 1000000007LL;
const Number MOD = LLONG_MAX;

vector<int> generate(int num) {
    int div = 2;
    vector<int> f;
    while (div * div <= num) {
	if ((num % div) == 0) {
	    int cnt = 1;
	    while ((num % div) == 0) {
		cnt *= div;
		num /= div;
	    }
	    f.pb(cnt);
	}
	div++;
    }
    if (num > 1)
	f.pb(num);
    
    vector<int> ans;
    forn (mask, (1 << sz(f))) {
	int multi = 1;
	forn (i, sz(f))
	    if (mask & (1 << i))
		multi *= f[i];
	ans.pb(multi);		
    }
    sort(ans.rbegin(), ans.rend());
    return ans;
}
Number M;
int N, L, R;

vector<int> gen[1001];
vector<Number> val[1001];

void process(int num) {
    for (int i = 0; i < sz(gen[num]); i++) {
	int e = gen[num][i];
	Number ans = M / e;
	for (int j = 0; j < i; j++) {
	    int e2 = gen[num][j];
	    if ((e2 % e) == 0)
		ans -= val[num][j];
	}
	val[num].pb(ans);
    }
}

void preprocess() {
    for (int i = 1; i <= R; i++) {
	val[i].clear();
	process(i);
    }
    //dp.clear();
}
Number dp[5000001][1<<5];

Number solve(int n, int mask, Number D) {
    if (n == 0)	return (mask == 0);
    Number ans = 0;
    for (int i = 0; i < sz(gen[d]); i++) {
	int e = gen[d][i];
	Number f = val[d][i];
	ans = ans + (solve(n - 1, d / e) * f);
	if (ans >= MOD) ans %= MOD;
    }
    return ans;
}

int main() {
    for (int i = 1; i <= 1000; i++)
	gen[i] = generate(i);
    //    int t;
    //scanf("%d", &t);
    //while (t--) {
    N = 5;
    //    M = 5;
    L = 0;
    R = N;
    for (M = 1; M <= N; M++) {
	     //	scanf("%d %lld %d %d", &N, &M, &L, &R);
	preprocess();
	Number ans = 0;
	for (int i = L; i <= R; i++) {
	    ans += solve(N, i);
	    if (ans >= MOD)
		ans -= MOD;
	}
	printf("%lld\n", ans);
    }
	//}
    return 0;
}
