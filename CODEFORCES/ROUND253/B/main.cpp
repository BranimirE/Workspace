#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
string cad;
int n;
bool isTandem(int ini, int tam){
	for(int i = ini; i < ini + tam && i + tam < n; i++)
		if(!(cad[i] == cad[i + tam] || cad[i] == '?' || cad[i + tam] == '?'))
			return false;
	return true;
}
int solve(){
	for(int l = n / 2; l >= 0; l--)
		for(int i = 0; i + l + l <= n; i++)
			if(isTandem(i, l))
				return l + l;
	return 0;
}
int main(){
	cin >> cad;
	int add;
	cin >> add;
	cad = cad + string(add, '?');
	n = cad.size();
	cout << solve() << endl;
	return 0;
}
