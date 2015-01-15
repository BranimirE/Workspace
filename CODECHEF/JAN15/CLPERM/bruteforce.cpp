#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <assert.h>
#include <set>
using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
bool in_set[10000];
bool notengo[123];
typedef long long int Number;
#define int Number
int solve(int n, vector<int> elim) {
    memset(in_set, false, sizeof(in_set));
    memset(notengo, false, sizeof(notengo));
    vector<int> tengo;
    tengo.pb(0);
    in_set[0] = true;
    for (int e: elim)
	notengo[e] = true;
    for (int i = 1; i <= n; i++) {
	if (notengo[i]) continue;
	for (int j = 0, tam = sz(tengo); j < tam; j++) {
	    int e = tengo[j];
	    if (in_set[e + i] == false) {
		tengo.pb(e + i);
		in_set[e + i] = true;
	    }
	}
    }
    for (int i = 1; ; i++)
	if (in_set[i] == false)
	    return i;
    return 0;
}

Number N, k;
vector<Number> v;

#define Number int

int main() {
#define int Number
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
