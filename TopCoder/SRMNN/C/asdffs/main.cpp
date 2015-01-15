#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << '\n';
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define MAXN 50010
typedef long long ll;
struct cuadrado{
	ll x1, x2, y1, y2;
	cuadrado() {}
	cuadrado(ll a, ll b, ll c, ll d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	ll area() {
		return (x2 - x1) * (y2 - y1);
	}
};
int n;
cuadrado v[MAXN];
vector<pair<pair<ll,ll>, int> > x1y1, x1y2, x2y1, x2y2, y1x1, y1x2, y2x1, y2x2;

bool vis[MAXN];
ll solve(int);
ll buscar(vector<pair<pair<ll,ll>, int> >& vec, ll igual, ll A, ll B) {
	pair<pair<ll,ll>, int>  tmp1(mp(igual, A), -1), tmp2(mp(igual, B + 1LL), -1);
	int i, j;
	i = lower_bound(all(vec), tmp1) - vec.begin();
	j = lower_bound(all(vec), tmp2) - vec.begin();
	ll ans = 0;
	for (; i < j; i++) {
		int id = vec[i].second;
		ans += solve(id);
	}
	return ans;
}

ll solve(int actual) {
	if (vis[actual])
		return 0LL;
	vis[actual] = true;
	ll ans = v[actual].area();
	ll x1, y1, x2, y2;
	x1 = v[actual].x1;
	y1 = v[actual].y1;
	x2 = v[actual].x2;
	y2 = v[actual].y2;
	//buscar a la derecha
	ans += buscar(x1y1, x2, y1, y2);
	ans += buscar(x1y2, x2, y1, y2);

	//buscar a la izquierda
	ans += buscar(x2y1, x1, y1, y2);
	ans += buscar(x2y2, x1, y1, y2);

	//buscar arriba
	ans += buscar(y1x1, y2, x1, x2);
	ans += buscar(y1x2, y2, x1, x2);

	//bucar abajo
	ans += buscar(y2x1, y1, x1, x2);
	ans += buscar(y2x2, y1, x1, x2);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll x1, y1,x2, y2, ancho, alto;
		scanf("%lld %lld %lld %lld", &x1, &y1, &ancho, &alto);
		x2 = x1 + ancho;
		y2 = y1 + alto;
		cuadrado tmp(x1, y1, x2, y2);

		v[i] = tmp;

		x1y1.pb(mp(mp(x1, y1), i));
		x1y2.pb(mp(mp(x1, y2), i));

		x2y1.pb(mp(mp(x2, y1), i));
		x2y2.pb(mp(mp(x2, y2), i));

		y1x1.pb(mp(mp(y1, x1), i));
		y1x2.pb(mp(mp(y1, x2), i));

		y2x1.pb(mp(mp(y2, x1), i));
		y2x2.pb(mp(mp(y2, x2), i));
	}
	sort(all(x1y1));
	sort(all(x1y2));

	sort(all(x2y1));
	sort(all(x2y2));

	sort(all(y1x1));
	sort(all(y1x2));

	sort(all(y2x1));
	sort(all(y2x2));

	memset(vis, false, sizeof(vis));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			ans = max(ans, solve(i));
		}
	}
	int adsf = 3, bb =2;
	ll tmp = adsf + bb;

	printf("%lld\n", ans);
	printf("%lld\n", tmp);
	/*  vector<pair<pair<int,int>, int> > vec;
  vec.pb(mp(mp(1, 2), 4));//0
  vec.pb(mp(mp(1, 3), 2));//1
  vec.pb(mp(mp(1, 4), 1));//2
  vec.pb(mp(mp(2, 2), 4));//3
  vec.pb(mp(mp(2, 3), 2));//4
  vec.pb(mp(mp(2, 4), 1));//5
  vec.pb(mp(mp(4, 2), 4));//6
  vec.pb(mp(mp(4, 3), 2));//7
  vec.pb(mp(mp(4, 4), 1));//8
  pair<int,int> sol = buscar(vec, 3, 0, 0);
  cout << sol.first << " " << sol.second << endl;*/
	return 0;
}

