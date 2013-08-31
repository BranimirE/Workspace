#include <iostream>
#include <cstring>

using namespace std;

string c;
int dp[1001][1001];
int solve(int l, int r){
	if(l >= r)
		return 0;
	
	int &ans = dp[l][r] ;
	if(ans == -1){
		if(c[l] == c[r])
			ans = solve(l+1, r-1);
		else
			ans = 1 + solve(l+1, r-1);

		ans = min(ans, 1 + min(solve(l+1, r), solve(l, r-1)));
	}
	return ans;		
}
int main(){
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> c;
		memset(dp, -1, sizeof dp);
		cout << "Case " << caso<<": " << solve(0, c.size()-1) << endl;
	}
	return 0;
}
