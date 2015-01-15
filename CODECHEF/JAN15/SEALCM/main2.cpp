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
const Number MOD = 1000000007LL;

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
//map<Number,int> dp[5000010];
//map<pair<int,Number>, int> dp;
void preprocess() {
    for (int i = 1; i <= R; i++) {
	val[i].clear();
	process(i);
    }
    //dp.clear();
}
/*
Number solve2(int n, Number d) {
    //    DBG(dp.size());
    if (n == 0)	return (d == 1);
    //    pair<int,Number> state = mp(n, d)    
    //    if (dp.count(state)) return dp[state];
    Number ans = 0;
    for (int i = 0; i < sz(gen[d]); i++) {
	int e = gen[d][i];
	Number f = val[d][i];
	ans = ans + (solve(n - 1, d / e) * f);
	if (ans >= MOD) ans %= MOD;
    }
    //    return dp[state] = ans;
    return ans;
    }*/
Number dp[2][5000010];
Number solve() {
    int from = 0, to = 1;
    for (int i = 0; i <= R; i++) {
	dp[from][i] = 0;
    }
    dp[from][1] = 1;
    for (int n = 1; n <= N; n++) {
	for (int d = 1; d <= R; d++) {
	    Number &ans = dp[to][d];
	    ans = 0;
	    for (int i = 0; i < sz(gen[d]); i++) {
		int e = gen[d][i];
		Number f = val[d][i];
		ans = (ans + dp[from][d / e] * f) % MOD;
	    }
	}
	swap(from, to);
    }
    Number ans = 0;
    for (int i = L; i <= R; i++) {
	ans = (ans + dp[from][i]) % MOD;
    }
    return ans;
}
int main() {
    for (int i = 1; i <= 1000; i++)
	gen[i] = generate(i);
    int t;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %lld %d %d", &N, &M, &L, &R);
	preprocess();
	/*	Number ans = 0;
	for (int i = L; i <= R; i++) {
	    ans += solve(N, i);
	    if (ans >= MOD)
		ans -= MOD;
		}*/
	printf("%lld\n", solve());
    }
    return 0;
}
