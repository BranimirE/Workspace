/*
ID: brani.e2
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <set>
#include <fstream>
using namespace std;

#define MAXN 12

#define N '0'
#define S '1'
#define E '2'
#define O '3'
#define vaca '0'
#define granjero '1'

char m[MAXN][MAXN];
int iv,jv,ig,jg;
char dirv,dirg;

void avanzar(int &i,int &j, char &dir){
	if(dir == N){
		if(m[i-1][j] != '*')
			i--;
		else
			dir = E;
	}else if(dir == S){
		if(m[i+1][j] != '*')
			i++;
		else
			dir = O;
	}else if(dir == E){
		if(m[i][j+1] != '*')
			j++;
		else
			dir = S;
	}else if(dir == O){
		if(m[i][j-1] != '*')
			j--;
		else
			dir = N;
	}
}
int main() {
	ifstream cin("ttwo.in");
	ofstream cout("ttwo.out");

	for(int i = 0; i < MAXN; i++)
		m[0][i] = m[i][0] = m[11][i] = m[i][11] = '*';

	for(int i = 1; i < MAXN-1; i++)
		for(int j = 1; j < MAXN-1; j++){
			cin >> m[i][j];
			if(m[i][j] == 'C'){
				iv = i; jv = j;
				//m[i][j] = '.';
				dirv = N;
			}
			if(m[i][j] == 'F'){
				ig = i; jg = j;
				//m[i][j] = '.';
				dirg = N;
			}
		}
	set<string> rep;
	string vacio = "";
	vacio =vacio + (char)('0'+iv)+ (char)('0'+jv) + dirv + (char)('0'+ig)+ (char)('0'+jg) + dirg;
	rep.insert(vacio);

	int sol = 0;
	while(!(iv==ig && jv==jg)){
		avanzar(iv,jv,dirv);//se mueven las vacas
		avanzar(ig,jg,dirg);//se mueven el granjero
		sol++;
		string tmp = "";
		tmp = tmp+ (char)('0'+iv)+ (char)('0'+jv) + dirv + (char)('0'+ig)+ (char)('0'+jg) + dirg;
		if(rep.count(tmp)){
			sol = 0;
			break;
		}
		rep.insert(tmp);

	}
	cout << sol << endl;
	return 0;
}
