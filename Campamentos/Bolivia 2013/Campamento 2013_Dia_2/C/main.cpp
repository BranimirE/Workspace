#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

string c;
int esCuadrada(string &cad){
	int n =  cad.size();
	if(n % 2 == 0){
		int i = 0, j = n / 2;
		while(i < j ){
			if(cad[i] != cad[i + j])
				return false;
			i++;
		}
		return true;
	}
	return false;
}
int solve(string cad){
	return 0;
}

int main(){
//	freopen("entrada.in","r", stdin);
	int casos;
	cin >> casos;
	while(casos--){
		cin >> c;
		cout << esCuadrada(c) << endl;
	}

	return 0;

}
