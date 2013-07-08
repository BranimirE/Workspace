#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
long long int t[101][101];

int N,C,i,j;
int main(){
	freopen("entrada.in","r",stdin);
	memset(t,0, sizeof t);
	for(i = 0; i < 101; ++i)
		t[i][0] = t[i][i] = 1;
	for(i = 2; i < 101; ++i)
		for(j = 1; j < i; ++j)
			t[i][j] = t[i-1][j] + t[i-1][j-1];
	while(cin >> N >> C && !(N == 0 && C == 0))
		cout << N << " things taken " << C << " at a time is " << t[N][C] << " exactly." << endl;
	return 0;
}
