#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int maxsec, nuts, divisors, maxeachsec;
	scanf("%d %d %d %d", &maxsec, &nuts, &divisors, &maxeachsec);
	int ans = 0;
	while(nuts > 0){
		if(divisors){
			int divisions = min(divisors + 1, maxsec);
			divisors -= (divisions - 1);
			nuts -= (divisions * maxeachsec);
		}else
			nuts -= maxeachsec;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
