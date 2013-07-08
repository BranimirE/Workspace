#include <iostream>

using namespace std;

int main() {
	int t,n;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n;
		cout << "Case "<<caso<<": "<<(((long long)1)<<(n+1))-1<<endl;
	}
	return 0;
}
