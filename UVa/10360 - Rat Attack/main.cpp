#include <cstdio>
#include <cstring>

using namespace std;
/************************ FAST READ *****************************/
char line[40];
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
/********************** END FAST READ ***************************/
#define MAXS 1025
int killed[1025][1025];
int d,n, x, y,p;
int main(){
	int t;
	t = getInt();
	while(t--){
		d = getInt();
		n = getInt();
		memset(killed, 0, sizeof(killed));
		while(n--){
			x = getInt();
			y = getInt();
			p = getInt();
			for(int i = x - d; i <= x + d; i++)
				for(int j = y - d; j <= y + d; j++)
					if(i >= 0 && i < MAXS && j >= 0 && j < MAXS)
						killed[i][j] += p;
		}
		x = y = p = 0;
		for(int i = 0; i < MAXS; i++)
			for(int j = 0; j < MAXS; j++)
				if(killed[i][j] > p){
					x = i;
					y = j;
					p = killed[i][j];
				}
		printf("%d %d %d\n", x, y, p);
	}
	return 0;
}
