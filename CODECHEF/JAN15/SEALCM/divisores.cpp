#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
vector<int> divisores(int num) {
    int div = 2;
    //(numero, potencia)
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
    for (int i = 0; i < sz(ans); i++)
	cout << ans[i] << " ";
    cout << endl;
    return ans;
}
int main() {
    divisores(1);
    return 0;
}
