#include <bits/stdc++.h>

using namespace std;
int n;
string v[120];
int cnt[120];
int mark(char car){
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(v[i][0] == car || v[i][1] == car){
			ans++;
			cnt[i]--;
		}
	return ans;
}
int main(){
	cin >> n;
	set<char> all;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		all.insert(v[i][0]);
		all.insert(v[i][1]);
	}
	string p(all.begin(), all.end());
	int ans = p.size();
	do{
		fill(cnt, cnt + n, 2);
		int tmp = 0;
		for(int i = 0; i < n; i++)
			if(mark(p[i]) > 1)
				tmp++;

	}while(next_permutation(p.begin(), p.end()));
	cout << ans << endl;
	return 0;
}
