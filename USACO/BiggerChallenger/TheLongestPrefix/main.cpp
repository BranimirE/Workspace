/*
ID: brani.e2
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <set>
#include <string.h>
#include <fstream>

using namespace std;

#define MAXP 11
#define MAXS 200001
string tmp,sec;
set<string> vec[MAXP];
int maxp = 0;
bool memo[MAXS];
bool posible(int pos){
	if(  pos == -1 || memo[pos])
		return true;
	for(int i = 1; i <= maxp && pos+1>=i; i++)
		if(vec[i].count(sec.substr(pos-i+1,i)))
			if(posible(pos-i))
				return (memo[pos-i] = true);
	return false;
}
int main() {
	ifstream cin("prefix.in");
	ofstream cout("prefix.out");

	int tam;
	while(cin>>tmp && tmp!="."){
		tam = tmp.size();
		vec[tam].insert(tmp);
		if(tam>maxp) maxp = tam;
	}

	sec = "";
	while(cin>>tmp)
		sec += tmp;
	//cout << "tamaño de sec = "<<sec.size() << endl;
	memset(memo,false, sizeof memo);
	int sol = -1;
	for(int i = -1; i <= (int)sec.size()-1; i++){
		//cout << "va en i = " << i << " sol = "<<sol+1<<endl;
		if(posible(i)){
			if(i!=-1)
				memo[i] = true;
			sol = max(i,sol);
		}
		if(i > sol+maxp)break;
	}
	cout << sol+1 << endl;
	return 0;
}
