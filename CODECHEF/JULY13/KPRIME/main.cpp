#include <iostream>
#include <fstream>

#define MAXN 100001

using namespace std;

int criba[MAXN];
int mem[MAXN][6];
void solve(){
	for( int i = 2; i < MAXN; ++i ){
		if(criba[i] == 0)
			for( int j = i; j < MAXN; j += i )
				criba[j]++;

		for( int k = 1; k < 6; ++k )
			mem[i][k] = mem[i-1][k];
		mem[i][criba[i]]++;
	}	
}
int main(){
	freopen("entrada.in", "r", stdin);
	solve();
	int casos, a, b, k , ans;
	cin >> casos; 
	while( casos-- ){
	cin >> a >> b >> k;
		ans = mem[b][k] - mem[a-1][k];
		cout << ans << endl;
	}
	return 0;
}
