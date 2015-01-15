#include <cstdio>
#include <map>

using namespace std;
map<long long int, int> m;
int main(){
	int t;
	long long int a,b, ans;
	scanf("%d", &t);
	while(t--){
		m.clear();
		scanf("%lld", &a);
		while(a--){
			scanf("%lld", &b);
			m[b]++;
		}
		scanf("%lld", &a);
		ans = 0;
		while(a--){
			scanf("%lld", &b);
			if(m[b]){
				ans++;
				m[b]--;
			}
		}
		printf("%lld\n",ans );
	}
	return 0;
}
