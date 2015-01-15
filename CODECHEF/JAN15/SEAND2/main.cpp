#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
string s;
int n;
int cnt[10];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
	cin >> s;
	cin >> n;
	forn (i, n) {
	    int tmp;
	    cin >> tmp;
	}
	memset(cnt, 0,sizeof(cnt));
	forn (i, sz(s))
	    cnt[s[i] - '0']++;
	forn (i, 10)
	    cout << string(cnt[i], '0' + i);
	cout << endl;
    }
    return 0;
}
