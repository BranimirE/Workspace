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
char cad[1000100];
int b[123];
int tam ;
int myrandom (int i) { return std::rand()%i;}
int getNum() {
    int ans = 0;
    forn (i, n) {
	int num = 0;
	forn (j, tam) {
	    num = ((num * 10) + cad[i] - '0') % b[i];
	}
	ans += num;
    }
    return ans;
}
int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
	cin >> s;
	tam = sz(s);
	cin >> n;
	forn (i, n) {
	    cin >> b[i];
	}
	memset(cnt, 0,sizeof(cnt));
	forn (i, sz(s))
	    cnt[s[i] - '0']++;
	string ans = "";
	forn (i, 10)
	    ans += string(cnt[i], '0' + i);
	forn (i, sz(ans))
	    cad[i] = ans[i];
	int best = INT_MAX;
	
	forn (aaa, 5) {
	    int nn = getNum();
	    if (nn < best) {
		best = nn;
		ans = string(cad, cad + tam);
	    }
	    random_shuffle(cad, cad + tam, myrandom);
	}
	int nn = getNum();
	if (nn < best) {
	    best = nn;
	    ans = string(cad, cad + tam);
	}
	cout << ans << endl;
    }
    return 0;
}
