#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

map<string,int> m;
vector<string> v[6];
void solve(){
	string tmp = " ";
	for(char i = 'a'; i <= 'z'; i++){
		tmp[0] = i;
		v[1].push_back(tmp);
	}

	for(int tam = 2; tam < 6; tam++){
		for(int i = 0; i < v[tam-1].size(); i++){
			string cad =  v[tam-1][i];
			for(char j = cad[cad.size()-1]+1; j <= 'z'; j++){
				string tmp = cad + j;
				v[tam].push_back(tmp);
					
			}
		}
	}
	int n = 1;
	for(int i = 1; i < 6; i++){
		for(int j = 0; j < v[i].size(); j++){
			m[v[i][j]] = n;
			n++;
		}
	}
}
int main(){
	solve();
	string cad;
	while(cin >> cad)
		cout << m[cad] << endl;
	return 0;
}
