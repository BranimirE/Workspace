#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
#define MAX 1005

char line[30*MAX];//OJO maximo mas 3 para el '\n' y el '\0'
int now = 0;
inline int getInt(){
	int n;
	int sign = 1;
	while(1)
		if(line[now]!=0){
			if((line[now]<'0' || line[now]>'9')){
                if(line[now] == '-')
                    sign = -1;
				now++;
				continue;
			}

			n = 0;
			while(line[now]>='0' && line[now]<='9') {
				n = n*10 + line[now] - '0';
				now++;
			}
			return n*sign;
		}
		else{
			gets(line);
			now = 0;
		}
	return sign*n;
}
int n;
int v[MAX];
int solve() {

    sort(v, v+n);
    int a,b,c,d;
    for(int d = n -1 ; d >= 0; d--)
        for(int a = 0; a < n; a++)
            if(a != d)
                for(int b = a + 1; b < n; b++)
                    if(b != d)
                        for(int c = b + 1; c < n; c++)
                            if(c != d && v[d] == v[a] + v[b] + v[c])
                                return v[d];
    return INT_MIN;
}
int main() {
    while(n = getInt()) {
        for(int i = 0; i < n; i++)
            v[i] = getInt();
        int ans = solve();
        if(ans != INT_MIN)
            printf("%d\n", ans);
        else
            puts("no solution");
    }
    return 0;
}
