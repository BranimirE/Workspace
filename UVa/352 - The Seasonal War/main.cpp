#include <iostream>
#include <fstream>
#define MAXN 30

using namespace std;

int dx[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1,  1,  0};

string c[MAXN + 2];
int n,ans, imgn;

void dfs(int x,int y){
	c[y][x] = '0';
	for(int i = 0; i < 8; ++i)
		if(c[y+dy[i]][x+dx[i]] == '1')
			dfs(x+dx[i], y+dy[i]);
}
int main(){
	c[0] = string(MAXN, '0');
	imgn = 1;
	while(cin >> n){
		for(int i = 1; i <= n; ++i){
			cin >> c[i];
			c[i] = "0" + c[i] + "0";
		}
		c[n+1] = string(MAXN,'0');
		ans = 0;
		for(int y = 1; y <= n; ++y)
			for(int x = 1; x <= n; ++x)
				if(c[y][x] == '1')
					dfs(x,y),ans++;
		cout << "Image number "<<imgn<<" contains "<<ans<<" war eagles."<<endl;
		imgn++;
	}	
	return 0;
}
