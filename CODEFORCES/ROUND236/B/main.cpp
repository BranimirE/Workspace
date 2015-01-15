#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int n, k, tmp;
	scanf("%d%d", &n, &k);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = (1<<28),size = -1;
	for(int height = 1; height <= 1000; height++){
		tmp = 0;
		for(int i = 0; i < n; i++)
			if((height + k*i) != a[i]) tmp++;
		if(tmp < ans){
			ans = tmp;
			size = height;
		}
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		int obj = size + k * i;
		if(obj != a[i])
			printf("%c %d %d\n", ((obj>a[i])?'+':'-'), i + 1, (int)abs(obj - a[i]));
	}
	return 0;
}
