/*
ID: brani.e2
PROG: transform
LANG: C++
 */
#include <iostream>
#include <fstream>
#define MAXN 12

using namespace std;
char origen[MAXN][MAXN],destino[MAXN][MAXN],tmp[MAXN][MAXN],nuevo[MAXN][MAXN];

int N;
bool cmp(){
	for(int i = 0; i < N;i++)
		for(int j = 0; j < N;j++)
			if(destino[i][j]!=tmp[i][j])
				return false;
	return true;
}

void origenatmp(){
	for(int i = 0; i < N;i++)
		for(int j = 0; j < N;j++)
			tmp[i][j] = origen[i][j];
}
bool rotartmp90(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			nuevo[i][j] = tmp[N-1-j][i];
	for(int i = 0; i < N;i++)
		for(int j = 0; j < N;j++)
			tmp[i][j] = nuevo[i][j];
	return cmp();
}
bool reflejartmp(){
	for(int i = 0; i < N; i++){
		int a=0,b = N-1,t;
		while(a<b){
			t = tmp[i][a];
			tmp[i][a] = tmp[i][b];
			tmp[i][b] = t;
			a++;b--;
		}
	}
	return cmp();
}
void mostrartmp(){
	cout << endl;
	for(int i = 0; i < N;i++){
		for(int j = 0; j < N;j++)
			cout << tmp[i][j];
		cout << endl;
	}
}
int main() {
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin >> N;
	fin.getline(origen[0],MAXN);
	for(int i = 0; i < N; i++)
		fin.getline(origen[i],MAXN);
	for(int i = 0; i < N; i++)
		fin.getline(destino[i],MAXN);
	origenatmp();

	if(rotartmp90()){
		fout << 1 << endl;
		return 0;
	}
	if(rotartmp90()){
		fout << 2 << endl;
		return 0;
	}
	if(rotartmp90()){
		fout << 3 << endl;
		return 0;
	}
	origenatmp();
	if(reflejartmp()){
		fout << 4 << endl;
		return 0;
	}
	if(rotartmp90()){
		fout << 5 << endl;
		return 0;
	}
	if(rotartmp90()){
		fout << 5 << endl;
		return 0;
	}
	if(rotartmp90()){
		fout << 5 << endl;
		return 0;
	}
	origenatmp();
	if(cmp()){
		fout << 6 << endl;
		return 0;
	}
	fout << 7<<endl;
	return 0;
}
