#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//freopen("entrada.in","r",stdin);

	int n;
	while(cin >> n && n){
		for(int k = 0; k < n; ++k){
			string cad, linea = "";
			cin >> cad;
			for(int i = 0; i < n; i++)
				linea += cad[i], linea += cad[i];
			cout << linea << endl;
			cout << linea << endl;
		}
	}

	return 0;
}


