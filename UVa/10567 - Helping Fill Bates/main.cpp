#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;
vector<int> v[300];
vector<int>::iterator it;
int main() {
    //freopen("in", "r", stdin);
    string s, ss;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        v[s[i]].push_back(i);
    int q;
    cin >> q;
    while(q--) {
        cin >> ss;
        int len = ss.length();
        int pos = 0, ini;
        bool sol = v[ss[0]].size();
        if(sol) {
            pos = ini = v[ss[0]][0];
            for(int i = 1; i < len && sol; i++) {
                char car = ss[i];
                it = lower_bound(v[car].begin(), v[car].end(), pos + 1);
                if(it != v[car].end())
                    pos = (*it);
                else
                    sol = false;
            }
        }
        if(sol)
            cout << "Matched "<< ini << " " << pos << endl;
        else
            cout << "Not matched" << endl;
    }
    return 0;
}
/*
bbbbbcccccaaaaa

aa
*/
