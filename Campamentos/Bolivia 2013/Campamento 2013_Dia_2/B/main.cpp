#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

vector<int> a;
vector<int> v[5];
int solve(int n0, int n1, int n2, int n3, int n4, int suma, int elim){
	if(n0 < 0 && n1 < 0 && n2 < 0 && n3 < 0 && n4 < 0)
		return -1;
	if(elim == 0){
		return suma;
	}else{
		int ans = -1;
		if(n0 >= 0  && suma >= v[0][n0] && suma-v[0][n0] % 4 != 0)
			ans = max(ans, solve(n0 - 1, n1, n2, n3, n4, suma - v[0][n0], elim-1));

		if(n1 >= 0  && suma >= v[1][n1] && suma-v[1][n1] % 4 != 0)
			ans = max(ans, solve(n0, n1 - 1, n2, n3, n4, suma - v[1][n1], elim-1));

		if(n2 >= 0  && suma >= v[2][n2] && suma-v[2][n2] % 4 != 0)
			ans = max(ans, solve(n0, n1, n2 - 1, n3, n4, suma - v[2][n2], elim-1));

		if(n3 >= 0  && suma >= v[3][n3] && suma-v[3][n3] % 4 != 0)
			ans = max(ans, solve(n0, n1, n2, n3 - 1, n4, suma - v[3][n3], elim-1));

		if(n4 >= 0  && suma >= v[4][n4] && suma-v[4][n4] % 4 != 0)
			ans = max(ans, solve(n0, n1, n2, n3, n4 - 1, suma - v[3][n4], elim-1));
		return ans;
	}
}

int main(){
	freopen("entrada.in","r", stdin);
	int casos, elim, n;
	int suma;
	cin >> casos;
	while(casos--){
		cin >> elim >> n;
		a.clear();
		int tmp, suma = 0;
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			suma +=  tmp;
			a.push_back(tmp);
		}
		sort(a.rbegin(), a.rend());

		for(int i = 0; i < 5; ++i)	
			v[i].clear();

		for(int i = 0; i < n; ++i){
			int t = a[i] % 5;
			v[t].push_back(a[i]);
		}
		vector<int> t(5);
		for(int i = 0; i < 5; ++i)
			t[i] = v[i].size();
		cout << solve(t[0]-1, t[1]-1, t[2]-1, t[3]-1, t[4]-1, suma, elim) << endl;

	}

	return 0;
}
