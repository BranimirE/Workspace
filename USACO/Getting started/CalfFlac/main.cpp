/*
ID: brani.e2
PROG: calfflac
LANG: C++
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#define MAXN 20100

using namespace std;
int N,i,j,izq,der,posi,dist;
string cad,tmp;
char v[MAXN];
int pos[MAXN];

void todoslosPalindromos(vector<int> &LP, int par){
	izq = der = -1;
	for(posi = 0; posi < N; posi++){
		dist = 0;
		if(posi <= der)
			dist = min(der - posi + par, LP[izq+der-(posi+par)]) + 1;
		while(posi-dist>=0 && posi+dist-par<N
				&& v[posi-dist]==v[posi+dist-par])
			dist++;
		LP[posi] = --dist;
		if(posi+dist-par > der){
			der = posi + dist - 1;
			izq = posi - dist ;
		}
	}

}
int main() {
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	getline(fin,cad);
	while(getline(fin,tmp))
		cad +='\n'+tmp;
	N = 0;
	for(i = 0; i < cad.length(); i++)
		if(isalpha(cad[i])){
			v[N] = tolower(cad[i]);
			pos[N] = i;
			N++;
		}
	v[N] = '\0';
	vector<int> LP(N,0),LI(N,0);
	todoslosPalindromos(LP,1);
	todoslosPalindromos(LI,0);
	int SOL1 = 0,SOL2 = 0;
	//primero en los de tamaño impar
	for(int i = 0; i < N; i++)
		if(LI[i]*2+1 > LI[SOL1]*2+1)
			SOL1 = i;

	for(int i = 0; i < N; i++)
		if(LP[i]*2 > LP[SOL2]*2)
			SOL2 = i;
	if(LI[SOL1]*2+1 > LP[SOL2]*2){
		izq = SOL1 - LI[SOL1];
		der = SOL1 + LI[SOL1];
	}else{
		izq = SOL2 - LP[SOL2];
		der = SOL2 + LP[SOL2]-1;
	}
	//cout << "cad = " << cad << endl;
	//cout << v << endl;
	//for(int i = 0; i < N;i++)
	//	cout << LP[i];
//	cout << endl;
	fout << der - izq + 1 <<   endl;
//	cout << izq << " " << der << endl;
	izq = pos[izq];
	der = pos[der];
	fout << cad.substr(izq,der-izq+1)<<endl;
	return 0;
}
