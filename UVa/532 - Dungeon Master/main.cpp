#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

int niv, filas, cols, ne, fe, ce, ns, fs, cs, n,f,c;
struct Nodo{
	int n,f,c;
	Nodo(){
		n = f = c = 0;
	}
	Nodo(int _n, int _f, int _c){
		n = _n;
		f = _f;
		c = _c;
	}
};
string m[32][32];
int d[32][32][32];
int dx[6] = { 0, 0, 1, -1, 0, 0};
int dy[6] = {-1, 1, 0,  0, 0, 0};
int dz[6] = { 0, 0, 0,  0, 1,-1};
queue<Nodo> q;
Nodo act, ady;
bool valid(int n, int f, int c){
	return n>=0 && n	<niv && f>=0 && f<filas && c>=0 && c<cols && (m[n][f][c]=='.' || m[n][f][c]=='E');
}
int main(){
	//freopen("entrada.in","r",stdin);
	while(cin >> niv>>filas >> cols && !(niv==0 && filas==0 && cols==0)){
		for(n = 0; n < niv; ++n)
			for(f = 0; f < filas; ++f){
				cin >> m[n][f];
				for(c = 0; c < cols; ++c){
					if(m[n][f][c] == 'S')
						ne = n, fe = f, ce = c;
					
					if(m[n][f][c] == 'E')
						ns = n, fs = f, cs = c;
				}
			}

		memset(d, -1 , sizeof d);
		d[ne][fe][ce] = 0;
		q.push(Nodo(ne,fe,ce));
		while(!q.empty()){
			act = q.front();q.pop();
			for(int i = 0; i < 6; ++i){
				f = act.f + dx[i];
				c = act.c + dy[i];
				n = act.n + dz[i];
				if(valid(n,f,c) && d[n][f][c] == -1){
					d[n][f][c] = d[act.n][act.f][act.c] + 1;
					q.push(Nodo(n,f,c));
				}

			}
		}
		int ans = d[ns][fs][cs];
		if(ans != -1)
			cout << "Escaped in " << ans << " minute(s)."<<endl;
		else
			cout << "Trapped!" << endl;
	}

	return 0;	
}
