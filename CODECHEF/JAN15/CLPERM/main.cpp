#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef unsigned long long int Number;
Number solve(Number n, vector<Number> &elim) {
    sort(all(elim));
    Number sum = 0;
    for(Number e: elim) {
	Number total = e * (e - Number(1)) / Number(2) - sum;
	if (total < e) return e;
	sum += e;
    }
    return n * (n + Number(1)) / Number(2) - sum + Number(1);
}
Number N, k;
vector<Number> v;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
	cin >> N >> k;
	v.resize(k);
	forn (i, k) cin >> v[i];
	cout << ((solve(N, v)&Number(1))?"Chef":"Mom") << endl;
    }
    return 0;
}
