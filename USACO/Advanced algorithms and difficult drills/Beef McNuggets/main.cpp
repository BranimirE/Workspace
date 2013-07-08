/*
ID: brani.e2
PROG: nuggets
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	ifstream cin("nuggets.in");
	ofstream cout("nuggets.out");
	
	int lim = 256*256 + 5;
	bool dp[lim];
	memset(dp, false, sizeof dp);

	int n;
	cin >> n;
	vector<int> p(n);
	int pes;
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	dp[0] = true;
	int sol = 0;
	for(int i = 1; i < lim; ++i){
		for(int j = 0; j < n; ++j)
			if(i-p[j] >= 0 && dp[i-p[j]]){
				dp[i] = true;
				break;
			}
		if(!dp[i])
			sol = i;
	}
	if(sol > (256*256)-(2*256))
		sol = 0;
	cout << sol << endl;
	return 0;
}
