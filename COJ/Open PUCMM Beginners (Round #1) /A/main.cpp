#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <stdio.h>

#define MAXN 51
#define MAXNi 2311

using namespace std;

int N;
int vec[MAXN];
bool criba[MAXNi];
vector<int> primos;
void generarCriba(){
	memset(criba, true, sizeof criba);
	criba[0] = criba[1] = false;
	for(int i = 2; i < MAXNi; i++)
		if(criba[i])
			for(int j = i + i; j*j < MAXNi; j += i)
				criba[j] = false;

	for(int i = 0; i < MAXNi; i++)
		if(criba[i])
			primos.push_back(i);
}
bool esValido(int n){
	int c = 0;
	int i = 0;
	while(n && i < primos.size() ){
		if(n%primos[i] == 0){
			c++;
			if(c == 3) return true;
			while(n && n%primos[i] == 0)
				n /= primos[i];
		}
		i++;
	}

	if(n>1)
		c++;

	return c>=3;
}
int main() {
	generarCriba();
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> vec[i];
	for(int i = 0; i < N; i++)
		if(!esValido(vec[i])){
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;

	return 0;
}
