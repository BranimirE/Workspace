#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, pair<int, int> > > v;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			v.push_back(make_pair(i + j - 1, make_pair(i, j)));
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i < k; i++)ans += v[i].first;
	cout << ans << endl;
	for(int i = k - 1; i >= 0; i--){//imprimo,los mas alejados primero
		for(int x = 1; x <= v[i].second.first;  x++)printf("(%d,%d) ", x, 1);
		for(int y = 2; y <= v[i].second.second; y++)printf("(%d,%d) ", v[i].second.first, y);
		puts("");
	}
	return 0;
}
