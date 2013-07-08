#include <stdio.h>

using namespace std;

int nrodivisores(int n){
	int sol = 1;
	int primo = 2,cnt;
	while(primo*primo<=n){
		cnt = 0;
		while(n%primo == 0){
			n /= primo;
			cnt++;
		}
		sol = sol*(cnt+1);
		if(primo == 2)	primo = 3;
		else primo += 2;
	}
	if(n!=1)
		sol = sol * 2;
	return sol;
}
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",nrodivisores(n-1)-1);
	}
	return 0;
}
