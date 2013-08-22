#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> contr;
string regla;

int nc;
int nr;
int tamregla, tamcontr;
int a[260];

void solve(int n){
	if(n == tamregla){
		for(int i = 0; i < tamregla; i++)
			if(regla[i] == '#')
				cout << contr[a[i]];
			else
				cout << (char)('0'+a[i]);
		cout << endl;
		return;
	}
	int lim;
	if(regla[n] == '#') lim = tamcontr;
	else lim = 10;
	for(int i = 0; i < lim; i++){
		a[n] = i;
		solve(n+1);
	}
}

int main(){
	//freopen("in", "r", stdin);
	while(cin >> nc){
		contr.clear();
		getline(cin , regla);
		tamcontr = nc;	
		while(nc--){
			getline(cin , regla);
			contr.push_back(regla);
		}

		cin >> nr;
		getline(cin, regla);
		while(nr--){
			getline(cin, regla);
			tamregla = regla.size();
			cout << "--" << endl;
			solve(0);
		}
	}
	return 0;
}
