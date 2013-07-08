/*
ID: brani.e2
PROG: milk
LANG: C++
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int N,D,a,b,C,t;
vector< pair<int,int> > vec;
int main() {

	ifstream fin("milk.in");
	ofstream fout("milk.out");
	fin >> D >> N;
	for(int i = 0; i < N; i++){
		fin >> a >> b;
		vec.push_back(make_pair(a,b));
	}
	sort(vec.begin(),vec.end());
	t = C = 0;
	for(int i = 0; i < N && C < D; i++){
		if(vec[i].second <= D-C){
			t += vec[i].first * vec[i].second;
			C += vec[i].second;
		}else{
			t += vec[i].first * (D-C);
			C = D;
		}
	}
	fout << t << endl;
	return 0;
}
