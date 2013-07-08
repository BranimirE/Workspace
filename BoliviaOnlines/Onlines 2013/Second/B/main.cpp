#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1<<30
#define MAXN 100100
#define PI acos(-1)

inline double max(double a, double b){return a>b?a:b;}

using namespace std;
vector<pair<pair<double, double>,int> > v;



int pos[MAXN];
bool solve(int a, int b){
	int ini = min(pos[a],pos[b]);
	int fin = max(pos[a],pos[b]);

	if(ini==fin)return true;

	double B;

	B = v[ini].first.second;
	int i = ini + 1;

	for(; i <= fin; i++)
		if(v[i].first.first > B)
			return false;
		else
			B = max(b, v[i].first.second);
	return (i == fin+1);
}
int main(){

	int t,n,m;
	double a,b,A,B;
	cin >> t;

	while(t--){
		cin >> n >> m;
		v.clear();
		for(int  i = 0; i < n; i++){
			cin >> a >> b;
			A = min(a,b);
			B = max(a,b);
			v.push_back(make_pair(make_pair(A,B),i));
		}
		sort(v.begin(),v.end());
//		for(int i = 0; i < n; i++)
//			cout << v[i].first.first << " " <<v[i].first.second << "("<<v[i].second <<") ";
//		cout << endl;
		for(int i = 0; i < n; i++)
			pos[v[i].second] = i;

		while(m--){
			cin >> a >> b;
			cout << (solve(a,b)?"YES":"NO") << endl;
		}
	}
 	return 0;
}
/*
1
2 1
1 2 2 3
0 1


1
5 3
6 8 5 7 3 5 0 3 2 4
0 1 4 0 3 2

3
2 1
1 2 2 3
0 1
5 3
6 8 5 7 3 5 0 3 2 4
0 1 4 0 3 2
4 3
3 4 5 8 6 7 1 2
0 1 1 2 2 3


 */

