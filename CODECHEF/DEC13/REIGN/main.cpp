#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100010
#define INF (1LL<<60)
typedef long long int Number;
vector<Number> v;
int n, k;
vector<Number> solve(const vector<Number> &vec){
	vector<Number> ans(n);
	Number maxsum = -INF, sum = 0;
	for(int i = 0; i < n; i++){
		sum += vec[i];
		maxsum = max(sum, maxsum);
		ans[i] = maxsum;
		if(sum < 0)
			sum = 0;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		v = vector<Number>(n);
		for(int i = 0; i < n; i++)
			scanf("%lld", &v[i]);
		vector<Number> a = solve(v);
		reverse(v.begin(), v.end());
		vector<Number> b = solve(v);
		reverse(b.begin(), b.end());
		Number sol = -INF;
		for(int i = 0; i + k + 1 < n; i++)
			sol = max(sol, a[i] + b[i + k + 1]);
		printf("%lld\n", sol);
	}
	return 0;
}
