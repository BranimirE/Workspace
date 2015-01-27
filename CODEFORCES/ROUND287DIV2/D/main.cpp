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
typedef long long int Number;
Number n, k, MOD;
Number powdies[1010];
Number dp[1001][101][2][2];
Number solve(Number pos, Number acu, bool llegoacero, bool distintodecero) {
    if (pos == 0)
	return llegoacero?1LL:0LL;
    Number &ans = dp[pos][acu][llegoacero][distintodecero];
    if (ans != -1) return ans;
    ans = 0;
    Number ceros = powdies[n - pos];
    Number ini = 0;
    if (pos == 1) ini = 1;
    for (Number digito = ini; digito <= 9; digito++) {
	Number numero = (((digito * ceros) % k) + acu) % k;
	bool Ynocero = distintodecero | (digito > 0);
	if (Ynocero && numero == 0)
	    ans = (ans + solve(pos - 1LL, numero, true, Ynocero)) % MOD;
	else
	    ans = (ans + solve(pos - 1LL, numero, llegoacero, Ynocero)) % MOD;
    }
    return ans;
}

int main() {
    cin >> n >> k >> MOD;
    powdies[0] = 1LL;
    for (int i = 1; i <= n; i++)
	powdies[i] = (powdies[i - 1] * 10LL) % k;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, 0, false, false) << endl;
    return 0;
}
