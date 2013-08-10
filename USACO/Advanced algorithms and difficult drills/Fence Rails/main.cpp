/*
ID: brani.e2
PROG: fence8 
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAXM 51
#define MAXO 1024

int libre[MAXM];
int peso[MAXO];
int tab, bar, libretotal, aacomodar;
using namespace std;

bool solve(int k, int um, int metidos){ // k-esimo objeto, ultima mochila donde fue puesto el (k+1)-esimo objeto
	if(k == -1)
		return true;
	int ini = 0;
	if(um != -1 && peso[k] == peso[k+1])
		ini = um;
	for(int i = ini; i < tab; ++i){
 
		if(libre[i] >= peso[k]){ // si cabe 
			//si hay tableros de mismo tamaño solo probamos poner el objeto en uno por que poner en los demas daria lo mismo :D
			if(i-1 != -1 && libre[i] == libre[i-1])
				continue;

			libre[i] -= peso[k];
			//aun puedo acomodar el mas pequeño
			if(k > 0 && !solve(0, -1, metidos + peso[k])){
				libre[i] += peso[k];
				continue;
			}
			
			// ya no entra el objeto mas pequeño en esta mochila
			if( k != 0 && libre[i] < peso[0] ){
				int sobraobligado = libre[i]; // ya que no entra nada mas en esta mochila
				// ¿ aun entra el resto de objetos k-1 en las otras mochilas ?
				int aunencajar = aacomodar - (metidos + peso[k]);
				int aunlibre = libretotal - (metidos + sobraobligado + peso[k]);
				if(aunencajar > aunlibre){
					libre[i] += peso[k];
					continue;
				}
			}

			bool tmp = solve(k-1, i, metidos + peso[k]);
			libre[i] += peso[k];
			if(tmp) return true;
		}
	}
	return false;
}
int main(){
	ifstream cin("fence8.in");
	ofstream cout("fence8.out");
	cin >> tab;
	libretotal = 0;
	aacomodar = 0;
	for(int i = 0; i < tab; ++i){
		cin >> libre[i];
		libretotal += libre[i];
	}
	sort(libre, libre + tab);

	cin >> bar;
	for(int i = 0; i < bar; ++i)
		cin >> peso[i];
	sort(peso, peso + bar);
	int ans = 0;
	for(int i = 0; i < bar; ++i){
		aacomodar += peso[i];
		if(aacomodar <= libretotal && solve(i, -1,0)){
			ans = i + 1;
		}
		else
			break;
	}
	cout << ans << endl;
	return 0;
}
