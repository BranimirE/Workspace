#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define MAXN 101

int banderas[MAXN];
double prob[MAXN];
int niveles;
double ans = 0;

void solve(int nivel, double cant, int a, int k){
	if(nivel == niveles){
		if(a >= k)
			ans += cant;
		return;
	}
	solve(nivel + 1, cant * prob[nivel]      , a + banderas[nivel], k                  );
	solve(nivel + 1, cant * (1 - prob[nivel]), a                  , k + banderas[nivel]);
}
int main(){
	freopen("entrada.in", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		cin >> niveles ;
		for(int i = 0; i < niveles; ++i)
			cin >> banderas[i];
		for(int i = 0; i < niveles; ++i){
			cin >> prob[i];
			prob[i] /= 100.0;
		}	
		ans = 0;
		solve(0, 1, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
