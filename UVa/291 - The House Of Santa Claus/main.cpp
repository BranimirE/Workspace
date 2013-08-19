#include <iostream>

using namespace std;
int m[6][6]={0};
void solve(int a, int sum, int sol){
	if(sum == 0){
		cout << sol<<"\\n" ;
		return;
	}
	for(int i = 1; i <= 5; ++i)
		if(m[a][i]){
			m[a][i] = m[i][a] = 0;
			solve(i,sum-2,sol*10 + i);
			m[a][i] = m[i][a] = 1;
		}
}
int main(){
	m[1][2] = m[1][3] = m[1][5] = 1;
	m[2][1] = m[2][3] = m[2][5] = 1;
	m[3][1] = m[3][2] = m[3][4] = m[3][5] = 1;
	m[4][3] = m[4][5] = 1;
	m[5][1] = m[5][2] = m[5][3] = m[5][4] = 1;
	solve(1, 16, 1);
	cout << endl;
	return 0;
}
