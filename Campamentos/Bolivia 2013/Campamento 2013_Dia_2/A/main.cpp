#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;
string c, ca, cb;

int mem[51][51];
int solve(int a, int b){
	if(a < 0 && b < 0)
		return 0;

	if(a < 0)
		return b + 1;
	if(b < 0 )
		return a + 1;
	
	
	int &ans = mem[a][b];
	if(ans == -1)
	{
		ans = 1<<30;
		if(ca[a] == cb[b])
			ans = min(ans,solve(a-1, b-1));
		else
			ans = min(ans, 1 + solve(a -1 , b - 1   )); // con un solo cambio lo convierto en el mismo car
		ans = min(ans, 1 + solve(a -1 , b    )); // elimino  de a o adiciono en b
		ans = min(ans, 1 + solve(a    , b - 1)); // elimino de b o adiciono en a
	}
	return ans;	
}
int main(){
	freopen("entrada.in","r", stdin);
	int casos;
	string cad;
	cin >> casos;
	while(casos--){
		cin >> cad;
		int n = cad.size();
		int ans = cad.size();
		string sa,sb;

		for(int i = 0; i <= n; ++i){
			ca = cad.substr(0,i);
			cb = cad.substr(i, n - i);
			memset(mem, 0, sizeof mem);
			
			ans = min(ans, sol(ca,cb));
			/*int tmp = solve(ca.size()-1, cb.size()-1);
			if(tmp < ans){
				ans = tmp;
				sa = ca;
				sb = cb;
			}*/
		}
		//cout << ans << "  "<< sa <<"  "<<sb<< endl;
		cout << ans << endl;
	}

	return 0;
}
