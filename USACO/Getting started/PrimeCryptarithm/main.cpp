/*
ID: brani.e2
PROG: crypt1
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int n,tmp,mul1,mul2,mask,a,b,c,d,e,SOL;
vector<int> vec;
bool esValido(int n){
	while(n && (mask & (1<<(n%10))))
		n /= 10;
	return n == 0;
}
int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	fin >> n;
	SOL = mask = mul1 = mul2 = 0;
	for(int i = 0; i < n; i++){
		fin >> tmp;
		mask = (1<<tmp) | mask;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	for(a = 0; a < n; a++){
		mul1 = mul1*10 + vec[a];
		for (b = 0; b < n; b++) {
			mul1 = mul1*10 + vec[b];
			for (c = 0; c < n; c++) {
				mul1 = mul1*10 + vec[c];
				for (d = 0; d < n; d++) {
					mul2 = mul2*10 + vec[d];
					for (e = 0; e < n; e++) {
						mul2 = mul2*10 + vec[e];
						tmp = mul1 * mul2;
						if( tmp>999 && tmp <= 9999 &&  esValido(tmp) &&
								((int)log10(mul1*vec[e])+1==3)	&& esValido(mul1*vec[e]) &&
								((int)log10(mul1*vec[d])+1==3)	&& esValido(mul1*vec[d]) ){
							SOL++;
							//cout << mul1 << " " << mul2 << endl;
						}
						mul2 /= 10;
					}
					mul2 /= 10;
				}
				mul1 /= 10;
			}
			mul1 /= 10;
		}
		mul1 /= 10;
	}
	fout << SOL << endl ;
	return 0;
}
