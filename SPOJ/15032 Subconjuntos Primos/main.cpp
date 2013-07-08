#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

#define MAXP 2000002 
using namespace std;

	string cad;
vector<long long int> leer(){

	stringstream  ss(cad);
	vector<long long int> s;
	long long int tmp;
	while(ss >> tmp)
		s.push_back(tmp);

	return s;
}
int main(){
	bool isPrime[MAXP];
	memset(isPrime, false, sizeof isPrime);
	isPrime[0] = isPrime[1] = true;
	for(int i = 4; i < MAXP; i += 2)
		isPrime[i] = true;
	for(int i = 3; i * i < MAXP; i += 2)
		if(!isPrime[i])
			for(int j = i + i; j < MAXP; j += i)
				isPrime[j] = true;
	
	while(getline(cin,cad)){
		vector<long long int> v = leer();
		int n =  v.size();
		bool sw = false;
		for(int mask = 1; mask <(1<<n); mask++){
			long long int s = 0;
			vector<long long int> c;
			for(int i = 0; i < n; i++)
				if(mask&(1<<i)){
					s += v[i];
					c.push_back(v[i]);
				}
			if(!isPrime[s]){
				for(int i = 0; i < c.size(); i++)
					cout << (i?" ":"") << c[i];
				sw = true;
				cout << endl;
			}
		}
		if(!sw)
			cout << "no existe" << endl;
		cout << "----------"<<endl;
	}
	return 0;
}
