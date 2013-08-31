#include <iostream>
#include <cmath>

using namespace std;
void imprimir(long long int nro){
	for(int i = 0; i < 47; ++i)
		if(nro &(1LL<<i))
			cout << 1 ;
		else
			cout << 0;
	cout << endl;

}
int ultimoBit(long long int i){
	long long int tmp =  (i & -i);
	//int ans = log10(tmp) / log10(2);
	return tmp;
}
long long int elibit(int i, long long int mask){
	long long int ans;
	long long int tmp =  ((1LL << (i + 1)) - 1);
	ans = ((mask & ~tmp)>>1LL) | ((tmp>>1LL)&mask) ;
	return ans;
}
int main(){
	//long long int nro = 1|(1LL << 1) | (1LL << 3) | (1LL << 5) | (1LL << 7) | (1LL << 9);
	long long int nro = (1LL << 3) | (1LL << 5) | (1LL << 7) | (1LL << 9);
	imprimir(nro);
	imprimir(ultimoBit(nro)); 
	cout << "ulb " << ultimoBit(nro) << endl;;
/*	while(nro){
		imprimir(nro);
		cout << "ultimo bit" << 
	}*/
	return 0;
}
