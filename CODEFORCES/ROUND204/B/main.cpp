#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
vector<int> v[MAX];
int main() {
  int n, tmp, lim = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    lim = max(lim, tmp);
    v[tmp].push_back(i);
  }
  vector<pair<int, int> > sol;
  for(int i = 1; i <= lim; i++)
    if(v[i].size() != 0) {
      if(v[i].size() == 1)
        sol.push_back(make_pair(i, 0));
      else {
        int diff = v[i][1] - v[i][0];
        bool issol = true;
        for(int j = 1; j < v[i].size() && issol; j++)
          issol = (v[i][j] - v[i][j-1]) == diff;
        if(issol)
          sol.push_back(make_pair(i, diff));
      }
    }
  cout << sol.size() << endl;
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].first << " " << sol[i].second << endl;
  return 0;
}
