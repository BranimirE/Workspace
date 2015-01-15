#include <cstdio>
#include <cstring>

using namespace std;

int n, tmp;
int c[10];
bool solve(){
	if(c[5] || c[7])return false;
	return (n%3==0 && n/3==c[1] && c[2]>=c[4] && c[6]>=(c[2]-c[4]) && (c[6]-(c[2]-c[4]))==c[3] );
}
int main(){
	while(scanf("%d", &n) != EOF){
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			c[tmp]++;
		}

		if(solve()){
			while(c[1] && c[2] && c[4]){
				puts("1 2 4");
				c[1]--;c[2]--,c[4]--;
			}
			while(c[1] && c[2] && c[6]){
				puts("1 2 6");
				c[1]--;c[2]--;c[6]--;
			}
			while(c[1] && c[3] && c[6]){
				puts("1 3 6");
				c[1]--;c[3]--;c[6]--;
			}
		}else
			puts("-1");
	}
	return 0;
}
