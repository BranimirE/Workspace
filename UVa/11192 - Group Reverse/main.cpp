#include <iostream>
#include <fstream>


using namespace std;

int main(){
//freopen("entrada.in", "r", stdin);
	int n,t;
	string c;
	while(cin >> n && n){
		cin >> c;
		t = c.size();
		n = t / n;
		for(int i = 0; i < t; i += n){
			int a = i, b = i + n - 1;
			while(a < b){
				swap(c[a],c[b]);
				a++, b--;
			}

		}
		cout << c << endl;
	}
	return 0;
}
