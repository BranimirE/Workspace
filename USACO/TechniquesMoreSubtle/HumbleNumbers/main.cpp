/*
ID: brani.e2
PROG: humble
LANG: C++
 */
#include <iostream>
#include <set>
#include <limits.h>
#include <fstream>

using namespace std;
#define MAXP 101

int nesimo,tam;
long long int primo;
set<int> sol,otro;
set<int>::iterator it,it2;
int main(){
	ifstream cin("humble.in");
	//ofstream cout("humble.out");
	while(tam--){
		cin >> primo;
		sol.insert(primo);
		for(it = sol.begin(); it != sol.end(); it++){
			long long int mult = (*it)*primo;
			if(mult > INT_MAX)break;
			it2 = sol.end();it2--;
			if(sol.size() > nesimo && mult > (*it2))break;
			sol.insert(mult);
		}
		if(sol.size()>nesimo){
			it = sol.begin();
			int m = nesimo;
			while(m--)it++;
			sol.erase(it, sol.end());
		}
	}
	it = sol.end();
	it--;
	cout << (*it) << endl;
	return 0;
}


