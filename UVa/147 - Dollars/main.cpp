#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

long long int v[11] = {10000, 5000, 2000, 1000, 500 , 200, 100, 50, 20, 10, 5};

long long int dp[11][30006];
long long int solve(int i, int sum){
	if( i < 0  or sum < 0)return 0;

	long long int & ans = dp[i][sum];
	if(ans == -1){
		if(sum == 0) ans =  1;
		else ans =  solve(i-1, sum) + solve(i, sum - v[i]);
	}
	return ans;
}
int main(){
	freopen("entrada.in","r",stdin);
	double obj = 30005;

	memset(dp, -1, sizeof dp);
/*	for(int i = 0; i < 11; i++)
		for(int j = v[i]; j <= 30005; j+=5)
			dp[j] += (dp[j-v[i]]) ;*/
	while(cin >> obj && obj!=0)
		printf("%6.2f%17lld\n", obj, solve(10, (int)(obj*100)));
	return 0;
}
