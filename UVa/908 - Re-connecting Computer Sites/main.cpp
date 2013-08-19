#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 1000000

using namespace std;

int parent[MAXN + 3];
void makeSet(int N){for(int i = 0; i <= N; ++i)	parent[i] = i;}
int Find(int x){return (x==parent[x])?x:(parent[x]=Find(parent[x]));}
void Union(int x, int y){parent[Find(x)] = Find(y);}

vector<pair<int, pair<int,int> > > edges;
int nodes;
long long int MST(){
	int length = edges.size();
	long long int ans = 0;
	sort(edges.begin(), edges.end());
	makeSet(nodes);
	for(int i = 0; i < length; ++i){
		int a = edges[i].second.first, b = edges[i].second.second;
		int cost = edges[i].first;
		if(Find(a) != Find(b)){
			Union(a,b);
			ans += cost;
		}
	}
	return ans;
}

int main(){
	bool newline = false;
	int a, b, c, k, m;
	long long int bestcost, newcost;
	while(cin >> nodes){
		if(newline)
			cout << endl;
		newline = true;
		bestcost = 0;

		for(int i = 1; i < nodes; ++i ){
			cin >> a >> b >> c;
			bestcost += c;
		}
		cout << bestcost << endl;
		edges.clear();
		cin >> k;
		while(k--){
			cin >> a >> b >> c;
			edges.push_back(make_pair(c, make_pair(a,b)));
		}
		cin >> m;
		while(m--){
			cin >> a >> b >> c;
			edges.push_back(make_pair(c, make_pair(a, b)));
		}
		newcost = MST();
		bestcost = min(bestcost, newcost);
		cout << bestcost << endl;
	}
	return 0;
}
