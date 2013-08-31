#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<string, pair<int,int> > > jug;
int at[1<<10 + 5], de[1<<10 + 5];
int main(){

	int t;
	cin >> t;
	string a; int b, c;
	for(int caso = 1; caso <= t; caso++){
		jug.clear();
		for(int i = 0; i < 10; i++){
			cin >> a >> b >> c;
			jug.push_back(make_pair(a, make_pair(b,c)));
		}
		sort(jug.begin(), jug.end());
		int ma = 0, md = 0, ans = 0;
		
		for(int mask = 0; mask < (1 << 10); mask++)
			if(__builtin_popcount(mask) == 5){
				int atak = 0, def = 0;

				for(int i = 0; i < 10; i++)
					if((1<<i)&mask)
						atak += jug[i].second.first;
					else
						def += jug[i].second.second;

				at[mask] = atak;
				de[mask] = def;
				ma = max(ma, atak);
			}
			else{
				at[mask] = 0;
				de[mask] = 0;
			}
		for(int i = 0; i < (1 << 10); i++)
			if(at[i] == ma && de[i] > md){
				md = de[i];
				ans = i;
			}
		string x,y, sx = "(",sy="(";
		x = "";
		y = "";
		cout << "Case "	<< caso << ":" << endl;
		for(int i = 0; i < 10; i++){
				if(ans & (1 << i)){
					x = x + sx + jug[i].first;
					sx = ", ";
				}
				else{
					y = y + sy + jug[i].first;
					sy = ", ";
				}
		}
		cout << x << ")" << endl;
		cout << y << ")" << endl;
	}
	return 0;
}
