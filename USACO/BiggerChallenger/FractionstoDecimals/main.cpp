/*
ID: brani.e2
PROG: fracdec
LANG: C++
 */
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;
string toString(int n){
	ostringstream sali;
	sali << n;
	return sali.str();
}
int main() {
	ifstream cin("fracdec.in");
	ofstream cout("fracdec.out");

	int N,D;
	cin >> N >> D;
	string sol = toString(N/D)+'.';
	N = N%D * 10;
	map<int,int> restos;//para almacenar los restos usados
	while(N)
		if(restos.count(N)){
			int pos = restos[N];
			sol = sol.substr(0,pos)+'('+sol.substr(pos,sol.size()-pos)+')';
			break;
		}
		else{
			restos.insert(make_pair(N,sol.size()));
			sol = sol + toString(N/D);
			N = N%D * 10;
		}
	if(sol[sol.size()-1]=='.')
		sol = sol + '0';


	for(int i = 0; i < sol.size(); i+=76)
		if(i + 76 < sol.size())
			cout << sol.substr(i,76)<<endl;
		else
			cout << sol.substr(i,sol.size()-i) << endl;




	return 0;
}

