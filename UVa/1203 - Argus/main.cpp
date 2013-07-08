#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define tiempo first
#define ID second
using namespace std;


vector<pair<int,int> > consultas;

int main(){
	//freopen("entrada.in","r",stdin);
	string cad;
	int a,b,k;
	while(cin >> cad){
		if(cad[0] == '#')break;
		cin >> a >> b;
		consultas.push_back(make_pair(b,a));
	}
	cin >> k;
	vector<pair<int,int> > vec(k+k); // tiempo , ID
	for(int i = 0; i < k; i++)
		vec[i] = make_pair(consultas[0].tiempo*(i+1), consultas[0].ID);
	for(int i = 1; i < consultas.size(); i++){
		int c, t;
		t = consultas[i].tiempo;
		c = consultas[i].ID;
		for(int j = k; j < k+k ; j++){
			vec[j] = make_pair(t,c);
			t += consultas[i].tiempo;
		}
		
		sort(vec.begin(), vec.end());
	}
	for(int i = 0; i < k; i++)
		cout << vec[i].ID <<endl; 
	return 0;
}
