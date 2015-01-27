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
int n;
int obj[123];
int dp[110][10010];
int sel[110][10010];
int solve(int i, int libre) {
    if (i == 0) return 0;
    int &ans = dp[i][libre];
    if (ans != -1) return ans;
    
    int tomo = 0, notomo = 0;
    if(obj[i] <= libre)
	tomo = 1 + solve(i - 1, libre - obj[i]);
    notomo = solve(i - 1, libre);
    if (tomo > notomo) {
	ans = tomo;
	sel[i][libre] = true;
    } else {
	ans = notomo;
    }
    return ans;
}
vector<int> tomados;
void reconstruir(int i, int libre) {
    if (i == 0) return;
    if (sel[i][libre]) {
	tomados.eb(i);
	reconstruir(i - 1, libre - obj[i]);
    } else {
	reconstruir(i - 1, libre);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int dias;
    cin >> n >> dias;
    for (int i = 1; i <= n; i++)
	cin >> obj[i];
    memset(dp, -1, sizeof(dp));
    memset(sel, false, sizeof(sel));
    cout << solve(n, dias) << endl;
    reconstruir(n, dias);
    forn (i, sz(tomados)) {
	if (i) cout << " ";
	cout << tomados[i];
    }
    if (sz(tomados))
	cout << endl;
    return 0;
}
