/*
ID: brani.e2
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
string uno(string c){
	for (int i = 0; i < (int)c.size(); ++i)
		if(c[i]=='1')
			c[i] = '0';
		else
			c[i] = '1';
	return c;
}
string dos(string c){
	for(int i = 0;i < (int)c.size();i+=2)
		if(c[i]=='1')
			c[i] = '0';
		else
			c[i] = '1';
	return c;
}
string tres(string c){
	for(int i = 1;i < (int)c.size();i+=2)
		if(c[i]=='1')
			c[i] = '0';
		else
			c[i] = '1';
	return c;
}
string cuatro(string c){
	for(int k = 0,i=3*k; i < (int)c.size(); k++,i=3*k)
		if(c[i]=='1')
			c[i] = '0';
		else
			c[i] = '1';
	return c;
}
vector<set<string> > vec;
set<string>::iterator it;
void preprocess(){
	set<string> tmp;
	tmp.insert(string(100,'1'));//ingresamos el de cero
	vec.push_back(tmp);
	for(int i = 0; i < 3; i++){
		set<string> aux;
		for(it = vec[i].begin();it != vec[i].end();it++)
			aux.insert(uno(*it)),aux.insert(dos(*it)),aux.insert(tres(*it)),aux.insert(cuatro(*it));
		vec.push_back(aux);
	}
}

int N,C,tmp=-1;
string cad(100,'X');

int main() {
	ifstream cin("lamps.in");
	ofstream cout("lamps.out");
	preprocess();
	cin >> N >> C >> tmp;
	while(tmp!= -1){
		cad[tmp-1] = '1';
		cin >> tmp;
	}
	cin >> tmp;
	while(tmp!= -1){
		cad[tmp-1] = '0';
		cin >> tmp;
	}
	set<string> sol;
	C = min(C, 3);
	for(it = vec[C].begin(); it != vec[C].end(); it++){
		string tmp = *it;
		bool esRespuesta = true;

		for(int i = 0; i < N && esRespuesta; i++)
			if(cad[i] != 'X')
				esRespuesta = (cad[i]==tmp[i]);
		if(esRespuesta)
			sol.insert(tmp.substr(0,N));
	}
	if(sol.size()==0)
		cout << "IMPOSSIBLE" << endl;
	else
		for(it = sol.begin(); it !=  sol.end(); it++)
			cout << (*it) << endl;
	return 0;
}
