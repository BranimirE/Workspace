#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100005
int n, k, w;
string v;
int s[MAX];
int c[MAX];
int solve(int pos){
	if(c[pos] != -1)return c[pos];
	int ans = (v[pos]=='1');
	if(pos + k <= n)
		ans += solve(pos + k);
	return c[pos] = ans;
}
int f(int l, int r){
	int total = s[r] - s[l-1];
	int correctos = solve(l + k - 1) - solve(r) + (v[r] == '1');
	int quitar = total - correctos;
	int deberiahaber = (r - (l + k - 1))/k + 1;
	int adicionar = deberiahaber - correctos;
	return quitar + adicionar;
}
int main(){
	cin >> n >> k >> w;
	cin >> v;
	v = "0" + v;
	s[0] = 0;
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + (v[i] == '1');
	memset(c, -1, sizeof(c));
	while(w--){
		int l, r;
		cin >> l >> r;
		cout << f(l, r) << endl;
	}
	return 0;
}
/*
10 3 3
1010100011
1 3
1 6
4 9

 */
