/*
ID: brani.e2
PROG: stamps
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXVAL 10000*200 + 5
#define oo 1<<30
int dp[MAXVAL]={0};
vector<int> valores;
int k,n,tmp;
int main() {
	ifstream cin("stamps.in");
	ofstream cout("stamps.out");
	cin >> k >> n;

	while(n--){
		cin >> tmp;
		valores.push_back(tmp);
	}
	sort(valores.rbegin(), valores.rend());
	int sol = 1;
	while(true){
		for(int i = 0;i < (int)valores.size(); i++)
			if(sol-valores[i] >= 0)
				if(dp[sol] == 0)
					dp[sol] = dp[sol-valores[i]]+1;
				else
					dp[sol] = min(dp[sol],dp[sol-valores[i]]+1);

		if(dp[sol] > k || dp[sol] == 0)
			break;//no se pudo construir el numero actual
		sol++;
	}
	cout << sol-1 << endl;

	return 0;

}
