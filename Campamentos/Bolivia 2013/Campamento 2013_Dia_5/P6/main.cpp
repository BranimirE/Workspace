#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio>

#define MAX 100010

using namespace std;

int padre[ MAX ];
int rango[ MAX ];

void MakeSet( int n ){for( int i = 0 ; i <= n ; ++i )padre[ i ] = i, rango[ i ] = 0;}
int Find(int x){return (padre[x]==x?x:padre[x]=Find(padre[x]));}
bool sameComponent(int x, int y){ return Find(x)==Find(y);}

void Union( int x , int y ){
    int xRoot = Find( x );
    int yRoot = Find( y );
    if( rango[ xRoot ] > rango[ yRoot ] )
        padre[ yRoot ] = xRoot;            
    else{                   
        padre[ xRoot ] = yRoot;
        if( rango[ xRoot ] == rango[ yRoot ] )
            rango[ yRoot ]++;
    }
}

int main(){
	//freopen("entrada.in", "r", stdin);
	int nodos, caminos, a, b;
	vector<pair<int, int> > c;
	bool valid[ MAX ];
	vector<int> elim, ans;
	while(scanf("%d%d",&nodos, &caminos) == 2){
		c.clear();
		elim.clear();
		ans.clear();
		c.push_back(make_pair(0,0));
		for(int i = 0; i < caminos; ++i){
			scanf("%d%d", &a, &b);
			c.push_back(make_pair(a,b));
		}
		memset(valid, true, sizeof valid);
		scanf("%d", &a);
		for(int i = 0; i < a; ++i){
			scanf("%d", &b);
			valid[b] = false;// elimino
			elim.push_back(b);
		}
		MakeSet(nodos);
		int componentes = nodos;
		int aa, bb;
		for(int j = 1; j <= caminos; ++j)
			if(valid[j]){
				aa = c[j].first;
				bb = c[j].second;
				if(!sameComponent(aa,bb)){
					componentes--;
					Union(aa,bb);
				}
			}
		for(int i = a-1; i >= 0; --i){
			ans.push_back(componentes);
			aa = c[elim[i]].first;
			bb = c[elim[i]].second;
			if(!sameComponent(aa, bb)){
				componentes--;
				Union(aa,bb);
			}
		}
		for(int i = a - 1; i >= 0; --i){
			printf("%d",ans[i]);
			if(i)printf(" ");
		}
		puts("");
	}
	return 0;
}
