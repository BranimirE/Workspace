#include <cstdio>
#include <algorithm>

#define MAXN 50005

using namespace std;

char line[1000000];
int now = 0;
inline int getInt(){
	int n;
	while(1)
		if(line[now]!=0){
			if(line[now]<'0' || line[now]>'9'){
				now++;
				continue;
			}
			n = 0;
			while(line[now]>='0' && line[now]<='9') {
				n = n*10 + line[now] - '0';
				now++;
			}
			return n;
		}
		else{
			gets(line);
			now = 0;
		}
	return n;

}

int N, q;
long long int val;

long long int v[MAXN];
int main(){
	N = getInt();
	for(int i = 0; i < N; i++){
		v[i] = getInt();
		if(i  && v[i-1] == v[i]){
			i--;
			N--;
		}
	}
	q = getInt();
	while(q--){
		val =  getInt();
		if(val < v[0])
			printf("X %lld\n", v[0]);
		else if(val > v[N-1])
			printf("%lld X\n", v[N-1]);
		else{
			int e = lower_bound(v, v+N, val) - v;
			int a,b;
			a = e, b = e;
			while(a>=0 && v[a] >= val)a--;
			while(b<N && v[b] <= val)b++;

			if(a==-1)printf("X ");
			else printf("%lld ", v[a]);

			if(b==N)printf("X\n");
			else printf("%lld\n", v[b]);
		}
	}
	return 0;
}
