#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
long long int solve(long long int N){
	long long int sum = 0;
	for(long long int i = 1; i <= N; i++)
		sum += (N/i);
	return sum;
}
int main(){
	/*int lim = 50;
	int ultimo = 0;
	for(int n = 1; n <= lim; n++){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				if(__gcd(i,j) == j)
					ans++;
		}
		cout << "n = " << n << " , ans = " << ans << "/"<< n*n<<" r = "<< ans - ultimo;
		cout << (solve(n)==ans?" bien ":" mal ")<< solve(n) << endl;
		ultimo = ans;
	}*/
	
	long long int N;
	while(cin >> N)
		cout <<N << " = " << solve(N) << endl;
	return 0;
}
