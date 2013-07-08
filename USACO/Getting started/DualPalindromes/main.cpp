/*
ID: brani.e2
PROG: dualpal
LANG: C++
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string s = "0123456789A";
int N,S;
string abase(int n, int base){
	string res = "";
	while(n){
		res = s[n%base] + res;
		n/=base;
	}
	return res;
}
int esPal(string cad){
	int i = 0, j = cad.size()-1;
	while(i < j){
		if(cad[i] != cad[j])
			return 0;
		i++,j--;
	}
	return 1;
}
bool esSol(int num){
	int c = 0;
	for(int i = 2; i<=10; i++){
		c += esPal(abase(num,i));
		if(c>1)return true;
	}
	return false;
}
int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	fin >> N >> S;
	S++;
	while(N){
		if(esSol(S)){
			fout << S << endl;
			N--;
		}
		S++;
	}
	return 0;
}

