#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> primos;
int a[20];
bool v[20];
void solve(int n){
	if(n == N ){
		for(int i = 0; i < primos.size(); ++i)
			if(primos[i] == a[n-1] +1){
				for(int i = 0; i < N; i++)
					cout << (i?" ":"") << a[i];
				cout << endl;
				break;
			}
		return;
	}
	for(int i = 0; i < primos.size(); i++){
		int r = primos[i] - a[n-1];
		if(r > N)break;
		if(r>1 && v[r]){
			v[r] = false;
			a[n] = r;
			solve(n+1);
			v[r] = true;
		}
	}
}
int main(){
	primos.push_back(2);
	primos.push_back(3);
	primos.push_back(5);
	primos.push_back(7);
	primos.push_back(11);
	primos.push_back(13);
	primos.push_back(17);
	primos.push_back(19);
	primos.push_back(23);
	primos.push_back(29);
	primos.push_back(31);
	int caso = 1;
	bool sw = false;
	a[0] = 1;
	for(int i = 0; i < 20; i++)
		v[i] = true;
	v[1] = false;
	while(cin >> N){
		if(sw)cout << endl;
		sw = true;
		cout << "Case "<<caso<<":" << endl;
		solve(1);
		caso++;
	}

	return 0;
}
