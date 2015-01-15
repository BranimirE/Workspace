#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cctype>

#define MAX 150010

using namespace std;

string frec, c;
char sol[257];
int f[257];
bool invec[257];

struct elem{
	int f;char car;
	elem(int _f, char _c){
		f = _f;
		car = _c;
	}
};
bool cmp(elem a, elem b){
	if(a.f == b.f)
		return a.car < b.car;
	return a.f < b.f;
}
int main(){
	int t;
	cin >> t;
	getline(cin , c);
	while(t--){
		getline(cin , frec);
		getline(cin , c);
		memset(f, 0, sizeof(f));
		for(int i = 0; i < c.size(); i++)
			if(isalpha(c[i]))
				f[tolower(c[i])]++;
		memset(invec, false, sizeof(invec));
		vector<elem> tmp;
		for(int i = 0; i < c.size(); i++)
			if(isalpha(c[i])){
				char car = tolower(c[i]);
				if(invec[car] == false){
					tmp.push_back(elem(f[car], car));
					invec[car] = true;
				}
			}

		sort(tmp.begin(), tmp.end(), cmp);

		for(int i = tmp.size() - 1, j = frec.size() - 1; i >= 0; i--, j--)
			sol[tmp[i].car] = frec[j];

		for(int i = 0; i < c.size(); i++)
			if(isalpha(c[i])){
				if(isupper(c[i]))
					c[i] = toupper(sol[tolower(c[i])]);
				else
					c[i] = sol[c[i]];
			}
		cout << c << endl;
	}
	return 0;
}
