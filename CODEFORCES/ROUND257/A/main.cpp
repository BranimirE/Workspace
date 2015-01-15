#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
int main() {
	vector<pair<int, int> > vec;
	int n, m;
	cin >> n >> m;
	vec.push_back(make_pair(0, 0));
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		vec.push_back(make_pair(i, a));
	}
	int last = 1;
	for(int i = 1; i < vec.size(); i++){
		last = vec[i].first;
		vec[i].second -= m;
		if(vec[i].second > 0)
			vec.push_back(vec[i]);
	}
	cout << last << endl;

	return 0;
}
