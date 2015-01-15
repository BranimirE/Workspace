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
int solve2(int n, vector<int> elim) {

    sort(all(elim));
    int sum = 0;
    for(int e: elim) {
	int total = e * (e - 1) / 2 - sum;
	if (total < e)
	    return e;
	sum += e;
    }
    return n * (n + 1) / 2 - sum + 1;
}
int main() {
    /*assert(solve(9, {3,  5,6,7,8}) == solve2(9, {3,  5,6,7,8}));
    
    assert(solve(9, {    5,6,7,8}) == solve2(9, {    5,6,7,8}));
    assert(solve(9, {3, 4, 5}) == solve2(9, {3, 4, 5}));

    assert(solve(17, {5}) == solve2(17, {5}));*/
    while(true) {
	int n = (rand() % 100) + 1;
	int k = rand() % (n + 1);
	k /= 2;
	set<int> elim;
	while (elim.size() < k) {
	    elim.insert((rand() % n) + 1);
	}
	vector<int> vec(all(elim));
	assert(solve(n, vec) == solve2(n, vec));
	cout << "N = " << n << endl;
	cout << "vec = {";
	for (int e: vec) {
	    cout << e << " ";
	}
	cout << "}" << endl << endl;
    }
    
    return 0;
}
