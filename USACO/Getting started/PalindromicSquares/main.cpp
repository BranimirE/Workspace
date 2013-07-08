/*
ID: brani.e2
PROG: palsquare
LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;
string val = "0123456789ABCDEFGHIJKL";
int base;
bool esPal(string& cad){
	int i = 0,j =cad.size()-1;
	while( i < j ){
		if(cad[i] != cad[j])
			return false;
		i++,j--;
	}
	return true;
}
string abase(int n){
	string res = "";
	while(n){
		res = val[n%base] + res;
		n/=base;
	}
	return res;
}
int main() {
	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");
	fin >> base;
	for(int num = 1; num <= 300; num++){
		string tmp = abase(num*num);
		if(esPal(tmp))
			fout << abase(num) << " "<<tmp<<endl;
	}

	return 0;
}
