/*
ID: brani.e2
PROG: shopping 
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>

#define MAXN 500

using namespace std;
struct oferta{
	int n;
	vector<int> c;//codigos - posiciones
	vector<int> k;//cantidad
	int precio;
};
int cod[1000];	

map<string, int> mapa;
vector<oferta> of;
string restar(int tam, string &a, string &b){
	string ans;
	for(int i = 0; i < tam; i++)
		ans.push_back(b[i]-a[i]+'0');
	return ans;
}
void evaluar(int pos, int tam,string cad, string oferta, int precio){
	if(pos == tam){
		string resta = restar(tam, oferta, cad );
		mapa[cad] = min(mapa[cad],mapa[resta]+precio);
		return;
	}
	for(int i = cad[pos]; i <= '5'; i++){
		cad[pos] = i;
		evaluar(pos+1, tam, cad,oferta,precio);
	}
}
void solve(int tam){
	for(int i = 0; i < of.size(); i++){
		string oferta(tam,'0');
		for(int j = 0; j < of[i].n; j++){
			assert(of[i].c[j]>=0 && of[i].c[j] < tam);
			oferta[of[i].c[j]] = of[i].k[j] + '0';
		}
		evaluar(0,tam, oferta, oferta, of[i].precio);
	}
}
int dp[6][5];
void transformar(vector<int> &vec, int obj, int cv){
	for(int i = 0; i < vec.size(); i++)
		if(vec[i]==obj)
			vec[i] = cv;
}
void llenar(int tam,int pos, string cad, int suma){
	if(pos == tam){
		mapa[cad] = suma;
		return;
	}
	for(int i = 0; i <= 5; i++)
		llenar(tam, pos + 1, cad + (char)('0' + i), suma + dp[i][pos] );
}
int main() {
	ifstream cin("shopping.in");
	ofstream cout("shopping.out");
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		oferta tmp;
		cin >> tmp.n;
		tmp.c = vector<int>(tmp.n);
		tmp.k = vector<int>(tmp.n);
		for(int j = 0; j < tmp.n; j++)
			cin >> tmp.c[j] >> tmp.k[j];
		cin >> tmp.precio;
		of.push_back(tmp);
	}
	int tam;
	cin >> tam;
	string comprar;
	for(int i = 0; i < tam; i++){
		int cod,precio,cant;
		cin >> cod;
		for(int j = 0; j < N; j++)
			transformar(of[j].c, cod, i);
		cin >> cant >> precio;
		comprar.push_back(cant+'0');
		for(int j = 0; j <= 5; j++)
			dp[j][i] = precio * j;
	}
	
	llenar(tam,0,"",0);
	solve(tam);

	cout <<mapa[comprar] << endl;
	
//	map<string,int>::iterator it ;
//	for(it = mapa.begin(); it != mapa.end(); it++)
//		cout << it->first << "  " << it->second << endl;

	
	
	return 0;
}
