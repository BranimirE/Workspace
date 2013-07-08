#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;
string toString(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

struct Digits{
	int d[10];
	Digits(){
		memset(d, 0, sizeof d);
	}
	Digits operator + (const Digits &o){
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] + o.d[i];
		return ans;
	}
	Digits operator + ( int n )	{
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] + n;
		return ans;
	}
	Digits operator - (const Digits &o){
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] - o.d[i];
		return ans;
	}
	Digits operator * (int n){
		Digits ans;
		for(int i = 0; i < 10; i++)
			ans.d[i] = d[i] * n;
		return ans;
	}
	void imprimir(){
		string space = "";
		for(int i = 0; i < 10; ++i){
			cout << space <<d[i];
			space = " ";
		}
		cout << endl;
	}

};

Digits c[10];

void precalcular(){ // calcula los digitos de potencias de 1 - pontencias de 10 
	for(int i = 1; i < 9 ; ++i){
		c[i] = c[i-1] * 10; // cada digito se necesitara x 10 por que se pondra 10 digitos distintos a  su izq
		c[i] = c[i] + pow(10,i-1); // le sumamos a cada digito cuanto tendra a la izq

		if(i != 1)
			c[i].d[0] -= 10;
	}
}
Digits get(int num){
	Digits ans;
	string n = toString(num);
	for(int i = 0; i < n.size(); ++i){

		int dig = n[i] - '0';
		int cant = n.size()-i-1;//dice cuantos digitos hay a la derecha del i-esimo digito

		// YXX..XX por cada digito 1 hasta 'dig' hay que volver a usar todos los c[cant]
		ans = ans + (c[cant] * dig) ;

		// cada digito desde 1 hasta (dig-1) tiene que repetirse XYYYY ZYYYY AYYYY
		for(int j = 1; j < dig; ++j)
			ans.d[j] += pow(10, cant );

		//el digito dig solo se usa la cantidad de numeros que hay a la derecha
		ans.d[dig] += (num % (int)pow(10,cant) )  ;
	}
	
	//ahora le sumaremos lo ceros adicionales generados por X0..01   X0...02
	for(int i = 0; i < n.size(); ++i){
		int dig = n[i] - '0';
		int cant = n.size() - i - 1;
		int adicionales = 0;
		for(int j = 1; j < cant; ++j)
			adicionales += pow(10, j);
		if(i == 0)//estamos en el primer digito
			ans.d[0] += ( (dig - 1) * adicionales);//los numero anteriores no tienen cero a la der ( 000001 no valido)
		else{
			ans.d[0] += (dig * adicionales);
			if( dig ) // si el digito no es cero entonces antes de dig hubieron ceros en esa posicion
				ans.d[0] += pow(10,cant);
		}
	}
	if(num < 10)
		ans.d[0]++;
	return ans;
}

int main(){
	freopen("entrada.in","r",stdin);
	
	precalcular();
	int ini,fin;
	while(cin >> ini >> fin && !(ini==0 && fin==0)){
		Digits a,b;
		a = get(ini);
		b = get(fin+1);
		(b-a).imprimir();
	}
	return 0;
}
