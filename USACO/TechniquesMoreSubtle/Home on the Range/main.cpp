/*
ID: brani.e2
PROG: range 
LANG: C++
*/
#include <iostream>
#include <fstream>
#define MAXN 251
using namespace std;
int N;
bool m[MAXN][MAXN];
int sol[MAXN]={0};
bool sePuede(int i,int j, int tam){
	bool ans = (i+tam<=N) && (j+tam<=N);
	tam--;
	for(int s = 0 ;  s <= tam && ans; s++)
		ans = m[i+tam][j+s] && m[i+s][j+tam];
	return ans;
}
int main(){
	ifstream cin("range.in");
	ofstream cout("range.out");
	cin >> N;
	string tmp;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		for(int j = 0; j < N; j++)
			m[i][j] = tmp[j]=='1';
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(m[i][j]){
				int tam = 2;
				while(sePuede(i,j,tam)){
					sol[tam]++;
					tam++;
				}

			}
		
	for(int i = 2; i < MAXN; i++)
		if(sol[i])
			cout << i << " " << sol[i]<<endl;

	return 0;
}
