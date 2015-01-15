#include <cstdio>
#define MAXN 50005

using namespace std;

char line[1000000];//OJO maximo mas 3 para el '\n' y el '\0'
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
int bs(int key){
	int l = 0, r = N - 1;
	while(l < r){
		int m = (l + r) >> 1;
		if(v[m] == key)break;
		if(v[m] <= key)
			l = m + 1;
		else
			r = m + 1 ;
	}
	return l;
}
int main(){
	//scanf("%d", &N);
	N = getInt();
	int n = N;	
	for(int i = 0; i < n; i++){
		//scanf("%lld", &v[i]);
		v[i] = getInt();
		if(i  && v[i-1] == v[i]){
			i--;
			N--;
			n--;
		}
	}
	//scanf("%d", &q);
	q = getInt();
	while(q--){
		//scanf("%lld", &val);
		val =  getInt();
		if(val < v[0])
			printf("X %lld\n", v[0]);
		else if(val > v[N-1])
			printf("%lld X\n", v[N-1]);
		else{
			int e = bs(val),a,b;
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
