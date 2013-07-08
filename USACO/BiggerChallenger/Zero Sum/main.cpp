/*
ID: brani.e2
PROG: zerosum
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
#define MAXN 9

int N;
string vec ="1+2+3+4+5+6+7+8+9+  ";
set<string> solution;
set<string>::iterator it;

int evaluar(){
	int acumulado = 0;
	int signo = '+';
	int tmp = 0;
	for(int i = 0; i <= (N-1)*2 + 1; i++){
		if(isdigit(vec[i])){
			tmp = tmp*10 + (vec[i]-'0');
		}else if(vec[i] == ' ')
			continue;
		else{
			if(signo == '+')acumulado+=tmp;
			else acumulado-=tmp;
			tmp = 0;
			signo = vec[i];
		}
	}
	return acumulado;
}
void solve(int n=1){

	if(n == (N-1)*2 + 1){
		if(evaluar()==0)
			solution.insert(vec.substr(0, n));
		return ;
	}
	vec[n] = '+';
	solve(n+2);
	vec[n] = '-';
	solve(n+2);
	vec[n] = ' ';
	solve(n+2);
}

int main() {
	ifstream cin("zerosum.in");
	ofstream cout("zerosum.out");
	cin >> N;
	solve();
	for(it = solution.begin(); it != solution.end(); it++)
		cout << (*it) << endl;
	return 0;
}
