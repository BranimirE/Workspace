#include <iostream>
#include <vector>
using namespace std;
int main() {
	int t;
	string c;
	cin >> t;
	while(t--){
		cin >> c;
		vector<pair<int, int> > ans;
		for(int rows = 1; rows <= 12; rows++)
			if(12 % rows == 0){
				int cols = 12 / rows;
				bool sw = false;
				for(int i = 0; i < cols && !sw; i++){
					bool sw2 = true;
					for(int j = i; j < 12 && sw2; j += cols)
						sw2 = c[j] == 'X';
					sw = sw2;
				}
				if(sw)
					ans.push_back(make_pair(rows, cols));
			}
		cout << ans.size();
		for(int i = 0; i < ans.size(); i++)
			cout << " " << ans[i].first << "x" << ans[i].second;
		cout << endl;
	}
	return 0;
}
/*
4
OXXXOXOOXOOX
OXOXOXOXOXOX
XXXXXXXXXXXX
OOOOOOOOOOOO

 */
