#include <iostream>
#include <fstream>

using namespace std;
struct Nodo{
	Nodo *izq;
	Nodo *der;
	char dato;

	Nodo(){
		dato = '\0';
		izq = NULL;
		der = NULL;
	}
} ;
int buscar(string &c, char car){
	for(int i = 0; i < c.size(); i++)
		if(c[i] == car)
			return i;
	return -1;
}
void solve(string &po, string &io, Nodo *nodo){
	nodo->dato = po[0];
	int pos = buscar(io, po[0]);
	string ioizq, ioder, poder, poizq;
	ioizq = io.substr(0,pos);
	ioder = io.substr(pos+1, io.size()-(pos+1));

	poizq = po.substr(1,ioizq.size());
	poder = po.substr(1+ioizq.size(),ioder.size());

	if(poizq.size()){
		Nodo tmp = Nodo();
		nodo->izq = &tmp;
		solve(poizq, ioizq,(*nodo).izq);
	}
	if(poder.size()){
		Nodo tmp = Nodo();
		nodo->der = &tmp;
		solve(poder, ioder,(*nodo).der);
	}
	cout << po[0];
}
int main(){
	ifstream cin("heritage.in");
	ofstream cout("heritage.out");

	Nodo arbol = Nodo();
	string io,po;
	cin >> io >> po;
	Nodo *raiz = &arbol;
	solve(po,io, raiz);
	cout << endl;
	return 0;
}
