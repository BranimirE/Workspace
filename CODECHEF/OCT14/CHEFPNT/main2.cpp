#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int> > solve(vector<vector<bool> > &t, int n, int m) {
  vector<pair<int, int> > ans;
  for (int fila = 1; fila <= n; fila++) {
    for (int col = 1; col <= m; col++) {
      if (t[fila][col]) {
	ans.push_back(make_pair(fila, col));
	while (col <= m && t[fila][col])
	  col++;
      }
    }
  }
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool> > t(n + 1, vector<bool>(m + 1, true));
  vector<vector<bool> > t2(m + 1, vector<bool>(n + 1, true));
  while (k--) {
    int i, j;
    cin >> i >> j;
    t[i][j] = false;
    t2[j][i] = false;
  }
  vector<pair<int,int> > A = solve(t, n, m), B = solve(t2, m, n);
  if (A.size() < B.size()) {
    cout << A.size() << endl;
    for (int i = 0; i < A.size(); i++)
      cout << A[i].first << " " << A[i].second << " " << 0 << endl;;
  } else {
    cout << B.size() << endl;
    for (int i = 0; i < B.size(); i++)
      cout << B[i].second << " " << B[i].first << " " << 1 <<  endl;
  }
  
  return 0;
}
