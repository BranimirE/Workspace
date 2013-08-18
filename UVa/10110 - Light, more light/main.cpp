#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
#define MAXP 66000

bitset<MAXP+2> criba;
vector<int> primos;
void generaPrimos(){
	criba.set();
	
	for(int i = 2;i <= MAXP; i++ )
		if(criba[i]){
			primos.push_back(i);
			for(int j = i + i; j <= MAXP; j += i)
				criba[j] = false;
		}
}
long long int divisores(long long int nro){
	int i = 0;
	long long int ans = 1;
	while(i < primos.size() && primos[i] * primos[i] <= nro){
		long long int tmp = 0;
		while(nro%primos[i] == 0){
			nro /= primos[i];
			tmp++;
		}
		ans = ans * (tmp + 1);
		i++;
	}
	if(nro > 1)
		ans *= 2;
	return ans;
}

int main(){
	generaPrimos();
	long long int nro;
	while(cin >> nro && nro){
		cout << ((divisores(nro)%2 == 0)?"no":"yes") << endl;
	}
	return 0;
}
