#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000010
typedef long long int Number;
Number T[MAX + 1];
int n;
Number v[MAX];
int lowbit(int i) {return (i & -i);}
Number sum(int i){
	Number value = 0;
	for(; i > 0; i -= lowbit(i))
		value += T[i];
	return value;
}
Number sum(int i, int j){
	return i > 1 ? sum(j) - sum(i-1) : sum(j);
}
void update(int i, Number value){
	for(; i <= n ; i += lowbit(i))
		T[i] += value;
}
int main() {
	int q;
	scanf("%d %d", &n, &q);
	memset(T, 0, sizeof(T));
	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
		update(i, v[i]);
	}
	while(q--){
		char op[5];
		Number a, b;
		scanf("%s %lld %lld", op, &a, &b);
		if(op[0] == 'S'){
			a++, b++;
			printf("%lld\n",sum(a, b));
		}else if(op[0] == 'G'){
			a++;
			update(a, b);
		}else{
			a++;
			update(a, -b);
		}
	}
	return 0;
}
