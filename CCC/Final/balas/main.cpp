#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
int b[1234];
int dist[1234];
bool v[1234];
int main(){
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> b[i];
		memset(dist, 0, sizeof(dist));
		fill(v, v + 1234, true);
		int vivos = 0;
		for(int i = 0; i < n; i++){
			vivos++;
			for(int j = i; j >= 0; j--)
				dist[j] += b[j];
			if(vivos >= 2){
				vector<int> convida;
				for(int k = 0; k <= i; k++){
					if(v[k]){
						convida.push_back(k);
					}
				}
				for(int k = 1; k < convida.size(); k++){


				}
			}

		}
	}

	return 0;
}
