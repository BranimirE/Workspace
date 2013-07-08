#include <fstream>
#include <cstdio>
#include <cstring>

const int MAXITEMS = 2005;
const int MAXCAP   = 2005;

using namespace std;

int espaciolibre, elementos;
int peso[MAXITEMS], ganancia[MAXITEMS];

int dp[MAXITEMS][MAXCAP];
int mochila(int elem, int libre){
	if(elem == -1)
		return 0;
	int &ans = dp[elem][libre];

	if(ans == -1 )
		if(peso[elem] <= libre) // ¿ el elemento elem cabe en el espacio libre en la mochila ?
			ans =  max(mochila(elem - 1, libre), ganancia[elem] + mochila(elem - 1, libre - peso[elem]));/*si cabe, asi que probamos cuando no tomamos el elemento y probamos si si metieramos el elemento*/
		else
			ans =  mochila(elem - 1, libre); /* no cabe, asi que lo ignoramos e intetamos meter los demas elementos */
	return ans;
}

int main(){
	freopen("entrada.in","r",stdin);

	scanf("%d%d", &espaciolibre, &elementos);
	for(int i = 0; i < elementos; i++)
		scanf("%d%d", &peso[i], &ganancia[i]);
	
	memset(dp, -1, sizeof dp);

	printf("%d\n", mochila( elementos -1, espaciolibre ));

	return 0;
}
