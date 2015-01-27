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
Number solve(Number altura, Number nodo, int dir) {
    if (altura == 0) return 1;
    Number hojas = 1LL << altura, grupo = hojas >> 1LL;
    Number ans = 0;
    if (nodo <= grupo) {//Tengo que ir a la izquierda(0)
	if (dir == 1) //primero visito el lado de la direccion
	    ans += (hojas - 1);
	ans += 1LL + solve(altura - 1, nodo, 1);
	
    } else {//Tengo que ir a la derecha(1)
	if (dir == 0)//primero visito el lado de la direccion
	    ans += (hojas - 1);
	ans += 1LL + solve(altura - 1, nodo - grupo, 0);
    }
    return ans;
}
int main() {
    Number h, n;
    cin >> h >> n;
    cout << solve(h, n, 0) - 1LL << endl;
    return 0;
}
