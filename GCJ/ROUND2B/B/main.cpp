#include <bits/stdc++.h>

using namespace std;
int n;
bool isUpDown(string &cad){
	int i = 1;
	while(i < n && cad[i] > cad[i - 1])
		i++;
	while(i < n && cad[i] < cad[i - 1])
		i++;
	return i == n;
}
int solve(string ini){
	if(isUpDown(ini))return 0;
	map<string, int> dist;
	queue<string> q;
	dist[ini] = 0;
	q.push(ini);
	while(!q.empty()){
		string u = q.front(); q.pop();
		int distU = dist[u];
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				string v = u;
				swap(v[i], v[j]);
				if(!dist.count(v)){
					//if(isUpDown(v))
						//return distU + 1;
					dist[v] = distU + 1;
					q.push(v);
				}
			}
	}
	sort(ini.begin(), ini.end());
	int ans = n * n;
	do{
		if(isUpDown(ini))
			ans = min(ans, dist[ini]);
	}while(next_permutation(ini.begin(), ini.end()));
	return ans;
}
int main() {
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cin >> n;
		vector<int> v(n), cp(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
			cp[i] = v[i];
		}
		sort(cp.begin(), cp.end());
		string cur = "";
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(v[i] == cp[j]){
					cur.push_back('0' + j);
					break;
				}
		printf("Case #%d: %d\n", caso, solve(cur));
	}
	return 0;
}
