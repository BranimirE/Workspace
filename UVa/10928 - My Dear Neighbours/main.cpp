#include <iostream>
#include <cstring>
#include <sstream>

#define MAXN 1000

using namespace std;

int m[MAXN + 3] = {0};

int main(){
	int casos, n, nro;
	string linea;
	cin >> casos;
	getline(cin, linea);
	while(casos--){
		cin >> n;
		getline(cin, linea);
		memset(m,0, sizeof m);
		for(int i = 1;i <= n; i++){
			getline(cin, linea);
			stringstream ss(linea);
			while(ss >> nro)
				m[i]++;
		}
		nro = n;
		for(int i = 1; i <= n; i++)
			nro = min(nro, m[i]);
		string space = "";
		for(int i = 1; i <= n; i++)
			if(m[i] == nro){
				cout <<space<< i;
				space = " ";
			}
		cout << endl;
		if(casos)
			getline(cin, linea);
	}
	return 0;
}
