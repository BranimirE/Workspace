#include <iostream>
#include <algorithm>

#define MAXN 22
using namespace std;
unsigned long long int fact[55];
void genera(){
	fact[0] = fact[1] = 1;
	for(unsigned long long int i = 2;i < 55; i++)
		fact[i] = fact[i-1] * i;
}
int cant[MAXN];
string ipermutacion(string cad, long long int th){
	sort(cad.begin(), cad.end());
	string sol = "";
	int pos;
	for(int c = cad.size() - 1; c >= 0; c--){
		pos = th / fact[c];
		th %= fact[c];
		sol += cad[pos];
		cad.erase(cad.begin() + pos);

	}
	return sol;

}	

int main(){
	int n,k;
	genera();
/*	while(cin >> n >> k && !(n == 0 && k == 0)){
		for(int i = 0; i < n; i++)
			cin >> cant[i];
		string cad = "";
	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < cant[i]; j++){
				cad = cad + (char)('a'+i);
			}
		}
		cout << cad << endl;
		cout << ipermutacion(cad, k + 10 ) << endl;
	}*/
	string cad;
	while(cin >> cad >> k){
		cout << ipermutacion(cad, k) << endl;
	}
	return 0;
}
