#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

#define MAXN 27

#define dormido     0
#define despierto   1
#define despertando 2
using namespace std;

int st[MAXN];	//estado
int cv[MAXN];	//cantidad de vecinos
int N;		//numero areas dormidas
int M;		//numero conexiones
vector<int> grafo[MAXN];
void leer(){
	memset(st, 0, sizeof st);
	memset(cv, 0, sizeof cv);
	//N ya va a ser leido para comprobar que aun hay entrada
	cin >> M;
	string t;	cin >> t;
	st[t[0]-'A'] = st[t[1]-'A'] = st[t[2]-'A'] = despierto;

	N -= 3;

	for(int i = 0; i < MAXN; i++) grafo[i].clear();
	
	while(M--){
		cin >> t;
		grafo[t[0]-'A'].push_back(t[1]-'A');
		grafo[t[1]-'A'].push_back(t[0]-'A');
	}
}
void solve(){
	int sol = 0;
	if(N == 0){
		cout << "WAKE UP IN, "<< sol << ", YEARS"<<endl;
		return;
	}

	while(true){
		bool hc = false;//hubo cambios

		for(int i = 0; i < MAXN; i++)
			if(st[i] == despierto){
				for(int j = 0; j < grafo[i].size(); j++)
					if(st[grafo[i][j]] == dormido){

						cv[grafo[i][j]]++;
						if(cv[grafo[i][j]] >= 3)
							st[grafo[i][j]] = despertando;

						grafo[i][j] = i;//para posteriormente ignorar el enlace
					}
			}
		for(int i = 0; i < MAXN; i++)
			if(st[i] == despertando){
				st[i] = despierto;
				N--;
				hc = true;

			}
		if(N == 0){
			cout << "WAKE UP IN, "<< sol << ", YEARS"<<endl;
			break;
		}
		if(!hc){
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
			break;
		}
	}
}
int main(){
	//freopen("entrada.in","r",stdin);

	while(cin >> N){
		leer();
		solve();
	}
	return 0;
}
