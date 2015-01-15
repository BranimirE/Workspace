#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 502

using namespace std;

int libros, escr;

long long int p[MAX], libre[MAX];

long long int ans ;
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> libros >> escr;
		long long int l = 0,r = 0;

		for(int i = 0; i < libros; i++){
			cin >> p[i];
			r += p[i];
			l = max(l, p[i]);
		}
		ans = r;
		while(l < r ){
			ans = (l + r) / 2; // cada escritor puede escribir hasta ans paginas
			long long sum = 0;
			int es = 0; // escritores necesarios para escribir todos los libros 
			for(int i = 0; i < libros; i++)	{
				if(sum + p[i] > ans){
					es++;
					sum = 0; // para el siguiente escritor
				}
				sum += p[i];
			}
			es++;// el ultimo escritor no fue contado por que ans siempre es mayor que cualquier libro
			if( es > escr )// si necesitamos mas escritores de los que tenemos 
				l = ans + 1; // entonces la repuesta tiene que ser mas grande
			else
				r = ans;
		}
		ans = l;

		//cout << " respini =  " << ans << endl;

		for(int i = 0; i < escr; i++)
			libre[i] = 0;

		int lib = libros-1;
		for(int i = escr-1; i >= 0; i--){
			long long int sum = 0;
			while(lib >= 0 && lib >= i && sum + p[lib] <= ans){
				sum += p[lib];
				libre[i]++;
				lib--;
			}
		}

		// imprimir sol
		lib = 0;
		for(int  i = 0; i < escr; i++){
			if(i)
				cout << " / ";
			int tmp = ans;
			string space = "";
			while(libre[i]--){
				cout << space;
				space = " ";
				cout << p[lib];
				lib++;
			}
		}
		cout << endl;
	}
	return 0;
}
