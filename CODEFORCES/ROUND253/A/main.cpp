#include <bits/stdc++.h>

using namespace std;

int main(){
	string cad;
	getline(cin, cad);
	set<char> ans;
	for(int i = 1; i < cad.size(); i += 3)
		if(isalpha(cad[i]))
			ans.insert(tolower(cad[i]));
	cout << ans.size() << endl;
	return 0;
}
