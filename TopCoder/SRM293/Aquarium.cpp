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
#include <cstring>

using namespace std;


class Aquarium {
public:
  int peaceful(int minSize, int maxSize, vector <int> fishSizes) {
    int ans = 0;
    vector<double> v = vector<double>(fishSizes.begin(), fishSizes.end());
    while(minSize <= maxSize){
      bool sw = true;
      double a = minSize;
      for(int i = 0; i < v.size() && sw; i++)
        if((v[i] >= a * 2.0 && v[i] <= a * 10.0) || (a >= v[i] * 2.0 && a <= v[i] * 10))
          sw = false;
      ans += sw;
      minSize++;
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	Aquarium *obj;
	int answer;
	obj = new Aquarium();
	clock_t startTime = clock();
	answer = obj->peaceful(p0, p1, p2);
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
	
	int p0;
	int p1;
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 12;
	int t2[] = {1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 36;
	int t2[] = {3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 10;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 1000;
	int t2[] = {10,100,500};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 880;
	int t2[] = {1,3,9,27,243,729};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 121;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 3;
	p1 = 997;
	int t2[] = {10,11,12,13,14,16,82,83,84,85,720,730,740,750,760,770};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 147;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 999;
	int t2[] = {941,797,120,45,7,120};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 10;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 1;
	p1 = 791;
	int t2[] = {1,4,12,25,79,556,625,800,801,950,952,954,956,958,980,1000};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
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