/*
ID: brani.e2
PROG: money
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAXSUM 10000
#define MAXMON 25
long long int memo[MAXSUM+1][MAXMON+1];
vector<int> v;
long long int solve(int sum,int t){
	if(sum>= 0 && t >= 0 && memo[sum][t] != -1)
		return memo[sum][t];

	if(sum == 0)
		return (long long int)1;
	if(sum < 0)
		return (long long int)0;
	if(t<0 && sum > 0)
		return (long long int)0;
	return (memo[sum][t] = solve(sum,t-1) + solve(sum-v[t], t));
}

int main(int argc, char **argv) {

	ifstream cin("money.in");
	ofstream cout("money.out");
	int cantmonedas, Sum;
	long long int tmp;
	cin >> cantmonedas >> Sum;
	for(int i = 0; i < cantmonedas; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	memset(memo,(long long int)-1,sizeof memo);
	cout << solve(Sum, cantmonedas-1) << endl;

	return 0;
}
