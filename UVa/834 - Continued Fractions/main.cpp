#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//freopen("entrada.in","r",stdin)	;
	long long int a, b;
	while(cin >> a >> b){
		cout << "["<< a/b;
		a %= b;
		swap(a,b);
		char sep = ';';
		while(b && a/b){
			cout << sep <<  a/b ;
			sep = ',';
			a %= b; swap(a,b);
		}
		cout << "]" << endl;
	}
	return 0;
}
