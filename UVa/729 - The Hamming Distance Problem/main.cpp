#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 20
int n,h;
char b[MAXN];
void solve(int bits, int pos){
	if(pos == n){
		if(bits == h)
			puts(b);
		return;
	}

	// pongo el bit
	b[pos] = '1';
	if(bits + 1 == h)
		solve(bits + 1, n);
	else
		solve(bits + 1, pos + 1);

	// no lo pongo
	b[pos] = '0';

	solve(bits    , pos + 1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> h;
		for(int i = 0; i < n;i++)b[i] = '0';
		b[n] = '\0';
		solve(0,0);

		if(t)
			cout << endl;
	}
	return 0;
}
