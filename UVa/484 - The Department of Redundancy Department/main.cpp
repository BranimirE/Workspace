#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main(){
	//freopen("entrada.in","r",stdin);
	map<long long int,int> m;
	vector<long long int> v;
	long long int tmp;
	while(cin >> tmp){
		if(m[tmp] == 0)
			v.push_back(tmp);
		m[tmp]++;
	}
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " " << m[v[i]] << endl;
	}
	return 0;
}
