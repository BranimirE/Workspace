/*
ID: brani.e2
PROG: barn1
LANG: C++
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define MAXO 202
#define x first
#define y second
using namespace std;

int M,N,S,C,o[MAXO],i,tmp,a,b,sol;
vector<pair<int,int> > vec;
int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	fin >> M >> S >> C;

	for(i = 0; i < C;i++)
		fin >> o[i];

	sort(o,o+C);
	i = 0;
	while(i < C){
		a = b = o[i];
		i++;
		while(i < C && o[i] == o[i-1]+1){
			b = o[i];
			i++;
		}
		vec.push_back(make_pair(a,b));
	}
	while(vec.size()>M){
		tmp = 0;
		for(i = 0; i <vec.size()-1; i++ )
			if(vec[i+1].x-vec[i].y < vec[tmp+1].x-vec[tmp].y)
				tmp = i;
		if(tmp+1 < vec.size()){
			vec[tmp].y = vec[tmp+1].y;
			vec.erase(vec.begin()+tmp+1,vec.begin()+tmp+2);
		}
	}
	sol = 0;
	for(i = 0; i < vec.size(); i++)
		sol+=(vec[i].y-vec[i].x+1);

	fout << sol << endl;
	return 0;
}
