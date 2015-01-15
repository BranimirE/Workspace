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
struct stn{
    Number sum, cnt[3];
    stn() {
	sum = -1LL; memset(cnt, 0, sizeof(cnt));
    }
    string toString() {
	stringstream ss;
	ss << "sum = " << sum;
	forn (i, 3)
	    ss << " cnt[" << i << "] = " << cnt[i];
	return ss.str();
    }
};
const int MAXN = 100000;
int n, q;
char cad[MAXN + 10];
stn t[4 * MAXN + 10];

stn unir(const stn &a, const stn &b) {
    stn ans;
    ans.sum = (a.sum + b.sum) % 3;
    forn (i, 3) ans.cnt[i] = a.cnt[i];
    forn (i, 3) ans.cnt[(a.sum + i) % 3] += b.cnt[i];
    return ans;
}
int maxnodo = 0;
void build(int nodo, int l, int r) {
    maxnodo = max(maxnodo, nodo);
    if (l == r) {
	t[nodo].sum = (cad[l] - '0') % 3;
	t[nodo].cnt[t[nodo].sum]++;
	return;
    }
    int m = (l + r) / 2;
    build(nodo * 2    , l    , m);
    build(nodo * 2 + 1, m + 1, r);
    t[nodo] = unir(t[nodo * 2], t[nodo * 2 + 1]);
}

stn query(int nodo, int l, int r, int i, int j) {
    if (j < l || i > r) return stn();
    if (i <= l && r <= j)return t[nodo];
    
    int m = (l + r) / 2;
    stn izq = query(2 * nodo, l, m, i, j),
	der = query(2 * nodo + 1, m + 1, r, i, j);

    if (izq.sum == -1) return der;
    if (der.sum == -1) return izq;

    return unir(izq, der);
}
void update(int nodo, int l, int r, int pos, int dig) {
    if (l == r) {
	t[nodo] = stn();
	t[nodo].sum = dig;
	t[nodo].cnt[t[nodo].sum]++;
	return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * nodo, l, m, pos, dig);
    else update(2 * nodo + 1, m + 1, r, pos, dig);
    t[nodo] = unir(t[2 * nodo], t[2 * nodo + 1]);
}
void update(int pos, int dig) {
    update(1, 1, n, pos, dig % 3);
}
Number query(int i, int j) {
    stn tmp = query(1, 1, n, i, j);
    Number ans = 0, N;
    forn (k, 3) {
	N = tmp.cnt[k];
	if (k == 0) N++;
	ans += (N * (N - 1LL) / 2LL); // C(N, 2) :D :D :D :D
    }
    return ans;
}
int main() {
    scanf("%d %d", &n, &q);
    scanf("%s", cad + 1);
    build(1, 1, n);

    while (q--) {
	int tipo, a, b;
	scanf("%d %d %d", &tipo, &a, &b);
	if (tipo == 1) {//UPDATE  
	    update(a, b);
	    /*	    for (int i = 1; i <= maxnodo; i++)
		cout<< " nodo " << i<< " " << t[i].toString() << endl;
	    cout << endl;
	    */
	} else
	    printf("%lld\n", query(a, b));
    }
    
    return 0;
}
