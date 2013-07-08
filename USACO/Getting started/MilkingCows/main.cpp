/*
ID: brani.e2
PROG: milk2
LANG: C++
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int N,a,b,i;
vector< pair<int,int> > vec,vec2;
int main() {

	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	fin >> N;
	for( i = 0; i < N; i++){
		fin >> a >> b;
		vec.push_back(make_pair(a,b));
	}
	sort(vec.begin(),vec.end());
	i = 0;
	while(i < N ){
		a =  vec[i].first; b = vec[i].second;
		while(i<N && vec[i].first<=b){
			b = max(b,vec[i].second);
			i++;
		}
		vec2.push_back(make_pair(a,b));
	}
	a = vec2[0].second-vec2[0].first;
	b = 0;
	for( i = 1; i < vec2.size(); i++){
		a = max(a,vec2[i].second-vec2[i].first);
		b = max(b,vec2[i].first-vec2[i-1].second);
	}
	fout << a << " " << b << endl;
}
