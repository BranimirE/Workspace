#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXITEMS = 1005;
const int MAXLIBRE = 1005;

int elementos, espaciolibre;
int peso[MAXITEMS];
int dp[MAXITEMS][MAXLIBRE];
int mochila(int elem, int libre){
	if(elem < 0)
		return 0;
	int &ans = dp[elem][libre];
	if(ans == -1)
		if(peso[elem] <= libre)
			ans = max(mochila(elem-1, libre), peso[elem] + mochila(elem-2, libre-peso[elem]));
		else
			ans =  mochila(elem-1, libre);
	return ans;
}
int main(){
	//freopen("entrada.in","r",stdin);
	int casos;
	scanf("%d", &casos);
	for(int caso = 1; caso <= casos; ++caso){
		if(caso != 1)
			puts("");
		scanf("%d%d", &elementos, &espaciolibre);
		for(int i = 0; i < elementos; ++i)
			scanf("%d", &peso[i]);
		memset(dp, -1, sizeof dp);
		printf("Scenario #%d: %d\n", caso, mochila(elementos-1, espaciolibre));
	}

	return 0;
}
