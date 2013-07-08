/*
ID: brani.e2
PROG: contact
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
#define MAXB 13
int A,B,N;
string cad,tmp;
vector<pair<string,vector<int> > > m[MAXB];
map<int,vector<string> > sol;
map<int,vector<string> >::reverse_iterator it;
vector<int> npos0, npos1;
int main(){
	ifstream cin("contact.in");
	ofstream cout("contact.out");
	cad = "";
	cin >> A >> B >> N;
	while(cin >> tmp)cad += tmp;
	vector<int> pos(cad.size());
	for(int i = 0; i < cad.size(); i++) 	pos[i] = i;
	m[0].push_back(make_pair("",pos));
	for(int tam = 1; tam <= B; tam++)
		for(int i = 0; i < m[tam-1].size(); i++){ // recorremos todos los patrones de tam = tam-1
			tmp = m[tam-1][i].first; // la cadena
			pos = m[tam-1][i].second; // las posiciones de ocurrencia
			npos0.clear();npos1.clear();
			for(int j = 0; j < pos.size() && pos[j]+tam-1 < cad.size(); j++)
				if(cad[pos[j]+tam-1] == '1')
					npos1.push_back(pos[j]);
				else
					npos0.push_back(pos[j]);
			if(npos0.size())	m[tam].push_back(make_pair(tmp+'0',npos0));
			if(npos1.size())	m[tam].push_back(make_pair(tmp+'1',npos1));
		}

	for(int tam = A; tam <= B; tam++)
		for(int i = 0; i < m[tam].size(); i++)
			sol[m[tam][i].second.size()].push_back(m[tam][i].first);
	it = sol.rbegin();
	while(N-- && it!=sol.rend()){
		vector<string> s = it->second;
		cout <<(it->first) <<endl;
		bool sw = false;
		for(int i = 0; i < s.size(); i++){
			if(sw)
				cout <<" ";
			cout << s[i];
			if((i+1)%6 == 0){
				cout << endl;
				sw = false;
				continue;
			}
			sw = true;
		}
		if(s.size()%6  != 0)
			cout << endl;
		it++;
	}

	return 0;
}
