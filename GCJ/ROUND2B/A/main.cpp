#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	int n, disc;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n >> disc;
		vector<int> v(n);

		for(int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int i = 0, j = n - 1;
		int ans = 0;
		while(i <= j){
			if(i == j){
				ans++;
				break;
			}
			if((v[i] + v[j]) <= disc)
				i++, j--;
			else
				j--;
			ans++;
		}
		printf("Case #%d: %d\n", caso, ans);
	}
	return 0;
}

