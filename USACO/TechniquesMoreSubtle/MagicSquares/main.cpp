/*
ID: brani.e2
PROG: msquare
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define MID 10000
int A(int n){
	int a,b;
	a = n%MID;
	b = n/MID;
	return a*MID + b;
}
int B(int n){
	int a,b;
	a = n%MID;
	b = n/MID;
	a = (a%10)*1000 + a/10;
	b = (b%10)*1000 + b/10;
	return b*MID + a;
}
int C(int n){
	int vec[8];
	for(int i = 7; i >= 0; i--){
		vec[i] = n%10;
		n /= 10;
	}
	int tmp = vec[1];
	vec[1] = vec[5];
	vec[5] = vec[6];
	vec[6] = vec[2];
	vec[2] = tmp;
	tmp = 0;
	for(int i = 0; i < 8; i++)
		tmp = tmp*10 + vec[i];
	return tmp;

}
set<int> visitado;
int tam = 0;
string bfs(int ini, int obj){
	int ady;
	queue<pair<int,string> > cola;
	cola.push(make_pair(ini,""));
	while(!cola.empty()){
		tam = max(tam,(int)cola.size());
		pair<int,string> actual = cola.front(); cola.pop();
		if(actual.first == obj) return actual.second;
		ady = A(actual.first);
		if(!visitado.count(ady)){
			visitado.insert(ady);
			cola.push(make_pair(ady,actual.second+'A'));
		}

		ady = B(actual.first);
		if(!visitado.count(ady)){
			visitado.insert(ady);
			cola.push(make_pair(ady,actual.second+'B'));
		}

		ady = C(actual.first);
		if(!visitado.count(ady)){
			visitado.insert(ady);
			cola.push(make_pair(ady,actual.second+'C'));
		}
	}
	return "-1";

}
int main() {
	ifstream cin("msquare.in");
	ofstream cout("msquare.out");
	int obj = 0 ,digit,m;
	for(int i = 0;i < 4; i++){
		cin >> digit;
		obj = obj*10 + digit;
	}
	obj *= MID;
	m = 1;
	for(int i = 0;i < 4; i++){
		cin >> digit;
		obj += digit*m;
		m*=10;
	}
	string sol = bfs(12348765,obj);
	cout << sol.size() << endl;
	int i=0;
	for(i = 0; i+60 <= sol.size(); i += 60)
		cout << sol.substr(i,i+60)<<endl;
	if(sol.size()%60)
		cout << sol.substr(i,sol.size()-i)<<endl;
	if(sol.size() == 0)cout << endl;

	return 0;
}
/*
6 1 5 4 3 2 7 8
14
ABBBCABBBCBBBC
 */
