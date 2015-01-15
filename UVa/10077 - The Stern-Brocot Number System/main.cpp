#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(pair<long long int, long long int> &a, pair<long long int, long long int> &b){
	return a.first*b.second < b.first*a.second;
}
int main(){
	long long int a,b;
	while(scanf("%lld %lld", &a, &b) == 2 and !(a==1 && b == 1)){
		pair<long long int, long long int> l,r, m,key;
		key = make_pair(a,b);
		l = make_pair(0,1);
		r = make_pair(1,0);
		while(cmp(l,r)){
			m = make_pair(l.first+r.first, l.second+r.second);
			if(m == key)
				break;
			if(cmp(m, key)){
				l = m;
				printf("R");
			}
			else{
				r = m;
				printf("L");
			}
		}
		puts("");
	}

	return 0;
}
