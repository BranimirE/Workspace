#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

int v[11] = {10000, 5000, 2000, 1000, 500 , 200, 100, 50, 20, 10, 5};

long long int dp[30006];
int main(){
	//freopen("entrada.in","r",stdin);
	double obj = 30005;

	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for(int i = 0; i < 11; i++)
		for(int j = v[i]; j <= 30005; j++)
			dp[j] += (dp[j-v[i]]) ;
	while(cin >> obj && obj!=0)
		printf("%.2f %d\n", obj, dp[(int)(obj*100)]);
	return 0;
}
