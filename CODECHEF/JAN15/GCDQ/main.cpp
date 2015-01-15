#include <bits/stdc++.h>

char line[700100];//OJO maximo mas 3 para el '\n' y el '\0'
int now = 0;
inline int getInt(){
    int n;
    while (true)
	if(line[now] != 0) {
	    if(line[now] < '0' || line[now] > '9') {
		now++;
		continue;
	    }
	    n = 0;
	    while(line[now] >= '0' && line[now] <= '9') {
		n = n * 10 + line[now] - '0';
		now++;
	    }
	    return n;
	}
	else {
	    gets(line);
	    now = 0;
	}
    return n;
}

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN 100010
int a[MAXN];
int t[4 * MAXN + 10];
int n, q;
int build(int nodo, int l, int r) {
    if (l == r) return t[nodo] = a[l];
    int mid = (l + r) / 2;
    return t[nodo] = __gcd(build(2 * nodo, l, mid), build(2 * nodo + 1, mid + 1, r));
}
int _query(int nodo, int l, int r, int i, int j) {
    if (r < i || l > j) return 0; // Fuera de rango
    if (i <= l && r <= j) return t[nodo]; //Esta completamente en el rango

    int mid = (l + r) / 2;
    int L = _query(2 * nodo    , l      , mid, i, j);
    int R = _query(2 * nodo + 1, mid + 1, r  , i, j);
    
    if (L && R) return __gcd(L, R);
    if (L) return L;
    
    return R;
}

int query(int i, int j) {
    return _query(1, 0, n - 1, i, j);
}

int solve(int l, int r) {
    if (l > 0 && r < (n - 1)) return __gcd(query(0, l - 1), query(r + 1, n - 1));
    if (l > 0) return query(0, l - 1);
    return query(r + 1, n - 1);
}

int main() {
    int t = getInt();
    while (t--) {
	n = getInt();
	q = getInt();
	forn (i, n) a[i] = getInt();
	build(1, 0, n - 1);
	while (q--) {
	    int l = getInt();
	    int r = getInt();
	    printf("%d\n", solve(l - 1, r - 1));
	}
    }
    return 0;
}
