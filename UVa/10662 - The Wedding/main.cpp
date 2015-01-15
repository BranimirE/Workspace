#include <iostream>
#include <cstring>
#include <climits>

#define MAX 21

using namespace std;

int t[MAX][MAX], r[MAX][MAX], h[MAX][MAX];
int ct[MAX], cr[MAX], ch[MAX];
int T, R, H;

int main(){
	while(cin >> T >> R >> H){
		memset(t, 0, sizeof t);
		memset(r, 0, sizeof r);
		memset(h, 0, sizeof h);
		for(int i = 0; i < T; i ++){
			cin >> ct[i];
			for(int j = 0; j < R; j++)
				cin >> t[i][j];		
		}
		for(int i = 0; i < R; i++ ){
			cin >> cr[i];
			for(int j = 0; j < H; j++)
				cin >> r[i][j];
		}
		for(int i = 0; i < H; i++){
			cin >> ch[i];
			for(int j = 0; j < T; j++)
				cin >> h[i][j];
		}
		int sa, sb,sc, sol = INT_MAX;
		bool haysol = false;
		for(int a = 0; a < T; a++)
			for(int b = 0; b < R; b++)
				for(int c = 0; c < H; c++)
					if(!t[a][b] && !r[b][c] && !h[c][a]){
						int sum = ct[a] + cr[b] + ch[c];
						if( sum < sol ){
							sa = a;
							sb = b;
							sc = c;
							sol = sum;
						}
					}
		if(sol != INT_MAX)
			cout << sa << " " << sb << " " << sc << ":" << sol << endl;
		else
			cout << "Don't get married!" << endl;
	}
	return 0;
}
