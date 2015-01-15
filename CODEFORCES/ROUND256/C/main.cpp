#include <bits/stdc++.h>
using namespace std;
typedef long long int Number;
int n;
int c[5010];
/*int tree[1000001];
void init(int node, int a, int b){
	if(a == b) {
		tree[node] = c[a];
		return;
	}
	init(2 * node + 1, a            , (a + b) / 2);
	init(2 * node + 2, (a + b)/2 + 1, b          );
	tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}
int query(int node,int a,int b,int p,int q){
	if(q < a || b < p) return INT_MAX;
	if(p <= a && b <= q) return tree[node];
	return min(query(2 * node + 1, a, (a + b) / 2, p, q), query(2 * node + 2, (a + b) / 2 + 1, b, p, q));
}*/
int solve(int l, int r, int painted = 0){
	if(l > r) return 0;
	int ans1 = r - l + 1;//all vertically
	int minimum = *min_element(c + l,  c + r + 1);
	int ans2 = minimum - painted;
	int ini = l, fin = l;
	while(ini <= r){
		while(ini <= r && c[ini] <= minimum)
			ini++;
		fin = ini;
		while(fin <= r && c[fin] > minimum)
			fin++;
		ans2 += solve(ini, fin - 1, minimum );
		ini = fin;
	}
	return min(ans1, ans2);
}
int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++)
			cin >> c[i];
		c[n] = 0;
		//init(0, 0, n - 1);
		cout << solve(0, n - 1) << endl;
	}
	return 0;
}
