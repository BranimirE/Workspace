#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		cout << n << " =  ";
		int d = 2;
		while(d*d<=n){
			while( n%d == 0 ){
				cout << d << " * ";
				n /= d;
			}
			d++;
		}
		if(n > 1)
			cout << n;
		cout << endl;
	}

	return 0;
}
