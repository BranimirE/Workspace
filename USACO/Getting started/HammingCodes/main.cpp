/*
ID: brani.e2
PROG: hamming
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n,bits,d;
vector<int> sol;
ofstream out("hamming.out");
int distancia(int a,int b){
	int mask = (1<<bits) - 1;
	return (bits-__builtin_popcount((a&b)|(((~a)&(~b))&mask)));
}
bool esSol(int num){
	bool sw = true;
	for(int i = sol.size()-1; i >= 0 && sw; i--)
		sw = (distancia(num, sol[i])>=d);
	return sw;
}
void solve(){
	string space = "";
	int lim = (1<<bits) - 1;
	for(int num = 0; num <= lim && sol.size()<n; num++)
		if(esSol(num)){
			if(sol.size()%10==0 && sol.size()!=0){
				space = "";
				out << endl;
			}
			out << space << num ;
			space = " ";
			sol.push_back(num);
		}
	out << endl;
}
int main() {
	ifstream in("hamming.in");
	in >> n >> bits >> d;
	solve();
	return 0;
}

