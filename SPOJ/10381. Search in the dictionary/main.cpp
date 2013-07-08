#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <fstream>

using namespace std;
struct Trie{
	Trie* hijos[26];
	bool esfin;
	vector<int> idhijos;
	Trie(){
		esfin = false;
		for(int i = 0; i < 26; ++i)
			hijos[i] = NULL;
	}
};
void insertar(Trie* v, char* c){
	if(c[0] == '\0')
		v->esfin = true;
	else{
		int k = c[0] - 'a';
		if(v->hijos[k] == NULL){
			v->hijos[k] = new Trie();
			(v->idhijos).push_back(k);
		}
		insertar(v->hijos[k], c+1);
	}
}
void ordenarids(Trie *t){
	sort((t->idhijos).begin(), (t->idhijos).end());
	int tam = (t->idhijos).size();
	for(int i = 0; i < tam; i++){
		int k = t->idhijos[i];
		ordenarids(t->hijos[k]);
	}
}
bool haysol = false;
int tmp, caso;
char vacio[25]="";
string cad;
void mostrar(Trie* v, string p, char* pr){
	if(pr[0] == '\0'){
		if(v->esfin){
			haysol = true;
			puts(p.c_str());
		}
		int tam = (v->idhijos).size();

		for(int i = 0; i < tam; ++i){
			int k = v->idhijos[i];
			mostrar(v->hijos[k], p + ((char)('a'+k)), vacio);
		}
	}
	else{
		int k = pr[0] - 'a';
		if(v->hijos[k] != NULL){
			bool aux = (v->hijos[k])->esfin;
			(v->hijos[k])->esfin = false;

			mostrar(v->hijos[k], p, pr+1);

			(v->hijos[k])->esfin = aux;

		}		
	}
}
int main(){
	//freopen("entrada.in","r",stdin);
	Trie* t;
	t = new Trie();
	scanf("%d", &tmp);
	char cadena[25];

	while(tmp--){
		scanf("%s", cadena);
		insertar(t, cadena);
	}
	ordenarids(t);;
	cin >> tmp;
	for(caso = 1; caso <= tmp; caso++){
		scanf("%s", cadena);
		cad = cadena;
		haysol = false;
		printf("Case #%d:\n", caso);
		mostrar(t, cad, cadena);
		if(!haysol)
			puts("No match.");
	}
	return 0;
}
