#include <iostream>
#include <sstream>
#include <cstring>
#include <bitset>
#include <set>

using namespace std;

string linea;
bitset<100> g[101];
set<string> ms;
int main(){
	int t;
	cin >> t;
	getline(cin, linea);
	int a,b, ans;
	while(t--){
		cin >> a >> b;
		int T = a;
		for(int i = 0; i < T; i++)
			g[i].reset();
		ms.clear();	
		getline(cin, linea);
		while(getline(cin, linea) && !linea.empty()){
			stringstream ss(linea);
			ss >> a >> b;
			a--;
			b--;
			g[a].set(b);
		}
		for(int i = 0; i < T; i++)
			ms.insert(g[i].to_string<char,char_traits<char>,allocator<char> >());
		
		cout << ms.size()<< endl;
		if(t)
			cout << endl;
	}
	return 0;
}
