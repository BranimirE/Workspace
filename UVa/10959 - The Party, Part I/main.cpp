#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

bool m[1001][1001];
int d[1001];
queue<int> q;


int main(){
	//freopen("entrada.in","r",stdin);
	int casos;
	cin >> casos;
	for(int caso = 0; caso < casos; caso++){
		if(caso)
			cout << endl;
		int N, edges;
		cin >>  N >> edges;
		memset(m,false, sizeof m);
		memset(d, -1,sizeof d);

		while(edges--){
			int a, b;
			cin >> a >> b;
			m[a][b] = m[b][a] = true;
		}
		
		d[0] = 0;
		q.push(0);
		
		while(!q.empty()){
			int act = q.front();q.pop();
			for(int i = 0; i < N; ++i)
				if(m[act][i] && d[i] == -1){
					d[i] = d[act] + 1;
					q.push(i);
				}
		}
		for(int i = 1; i < N; ++i)
			cout << d[i] << endl;

	}
	return 0;
}
