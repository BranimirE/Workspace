#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

struct UnionFind{
  int p[MAX], r[MAX], setSize[MAX];
  int n, numSets;
  UnionFind(int _N){
    reset(_N);
  }
  void reset(int N){
    n = N;
    numSets = n;
    for(int i = 0; i <= n; i++){
      p[i] = i;
      r[i] = 0;
      setSize[i] = 1;
    }
  }
  int Find(int i){return (p[i] == i)?i:(p[i] = Find(p[i]));}
  bool sameComponent(int i, int j){return Find(i) == Find(j);}
  void Union(int i, int j){
    if(!sameComponent(i, j)){
      numSets--;
      int x = Find(i), y = Find(j);
      if(r[x] > r[y]){
        p[y] = x;
        setSize[x] += setSize[y];
      } else                   {
        p[x] = y;
        setSize[y] += setSize[x];
        if (r[x] == r[y]) r[y]++;
      }
    }
  }
  int numDisjointSets(){
    return numSets;
  }
  int sizeOfSet(int i){
    return setSize[Find(i)];
  }
};

class ChristmasTreeDecoration {
public:
  int solve(vector <int> col, vector <int> x, vector <int> y) {
    vector<pair<int, pair<int, int> > > g;
    int n = col.size();
    for (int i = 0; i < x.size(); i++) {
      int u = x[i] - 1, v = y[i] - 1;
      if (col[u] != col[v]) {
	g.push_back(make_pair(0, make_pair(u, v)));
      } else {
	g.push_back(make_pair(1, make_pair(u, v)));
      }
    }
    sort(g.begin(), g.end());
    UnionFind uf(n);
    int ans = 0;
    for (int i = 0; i < g.size() && uf.numDisjointSets() > 1 ; i++) {
      int u = g[i].second.first, v = g[i].second.second;
      if (!uf.sameComponent(u, v)) {
	ans += g[i].first;
	uf.Union(u, v);
      }
    }
    return ans;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	ChristmasTreeDecoration *obj;
	int answer;
	obj = new ChristmasTreeDecoration();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {1,1,2,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,1,2,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,4,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,1,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {50,50,50,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,1,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,4,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,4,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,1,1,2,2,2,3,3,3,4,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 5;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
