#include <cstdio>
#include <cstring>
#define MAX 310
using namespace std;
struct Cont{
	int v[10];
	Cont(){memset(v, 0, sizeof(v));}
	Cont operator + (Cont o){
		Cont ans;
		for(int i = 0; i < 10; i++)
			ans.v[i] = v[i] + o.v[i];
		return ans;
	}
	Cont operator - (Cont o){
		Cont ans;
		for(int i = 0; i < 10; i++)
			ans.v[i] = v[i] - o.v[i];
		return ans;
	}
};
int n;
Cont m[MAX][MAX];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
			int tmp;
			scanf("%d", &tmp);
			m[i][j].v[tmp - 1]++;
		}
	int q, x1, y1, x2, y2;
	scanf("%d", &q);
	while(q--){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		Cont ans = m[x2][y2];
		ans = ans -  m[x1 - 1][y2];
		ans = ans -  m[x2][y1 - 1];
		ans = ans +  m[x1 - 1][y1 - 1];
		int sol = 0;
		for(int i = 0; i < 10; i++)
			if(ans.v[i])
				sol++;
		printf("%d\n", sol);
	}
	return 0;
}
