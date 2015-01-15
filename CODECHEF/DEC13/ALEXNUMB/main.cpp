#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define MAX 100005
int n;
int v[MAX], ord[MAX];
void preprocesar(){
	for(int i = 0; i < n; i++)
		ord[i] = v[i];
	sort(ord, ord + n);
	for(int i = 0; i < n; i++)
		v[i] = lower_bound(ord, ord + n, v[i]) - ord + 1;
}
int T[MAX + 1];
int lowbit(int i) {
	return (i & -i);
}
int sum(int i){
	int value = 0;
	for(; i > 0; i-= lowbit(i))
		value+= T[i];
	return value;
}
int sum(int i, int j){
	return i > 1 ? sum(j) - sum(i-1) : sum(j);
}
void update(int i, int value){
	for(; i <= n ; i += lowbit(i))
		T[i] += value;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		preprocesar();
		memset(T, 0, sizeof(T));
		long long int ans = 0;
		for(int i = 0; i < n; i++){
			ans += sum(1, v[i]);
			ans += sum(v[i], n);
			update(v[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
