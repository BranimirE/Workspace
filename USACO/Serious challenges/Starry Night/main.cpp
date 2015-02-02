/*
ID: brani.e2
PROG: starry
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
struct Data {
  int x, y;
  Data(int _x, int _y):x(_x), y(_y) {}
  bool operator <(const Data &other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }
  bool operator == (const Data &other) const {
    return (x == other.x && y == other.y);
  }
};

struct Star {
  vector<Data> forms[8];
  void normalize() {
    for (int i = 0; i < 8; i++) {
      vector<Data> &vec = forms[i];
      assert(vec.size() > 0);
      int minx = INT_MAX, miny = INT_MAX;
      for (Data e: vec) {
	minx = min(minx, e.x);
	miny = min(miny, e.y);
      }
      for (Data &e: vec) {
	e.x -= minx;
	e.y -= miny;
      }
      sort(vec.begin(), vec.end());
    }
    sort(forms, forms + 8);
  }
  bool operator == (const Star &other) const {
    for (int i = 0; i < 8; i++)
      if (forms[i] != other.forms[i])
	return false;
    return true;
  }
};

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};
int m, n;
string mapa[102];
char v[123][123];
int id[123][132];
int ID[123][123];
int N;
int nid;
void dfs(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m || id[i][j] != -1 || v[i][j] == '0') return;
  id[i][j] = nid;
  for (int k = 0; k < 8; k++)
    dfs(i + dx[k], j + dy[k]);
}
Star stars[510];
int form;
void takeinfo() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int key = id[i][j];
      if (key != -1)
	stars[key].forms[form].push_back(Data(i, j));
    }
}
int temp[123][123];
void rotate() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      temp[N - j - 1][i] = id[i][j];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      id[i][j] = temp[i][j];
}
void inverse() {
  for (int i = 0; i < N; i++) {
    int l = 0, r = N - 1;
    while (l < r) {
      swap(v[i][l], v[i][r]);
      swap(id[i][l], id[i][r]);
      l++;
      r--;
    }
  }
}
char label[510];
int main() {
  freopen("starry.in", "r", stdin);
  freopen("starry.out","w", stdout);
  cin >> m >> n;
  for (int i = 0; i < n; i++)
    cin >> mapa[i];
  N = max(n, m);
  memset(v, '0', sizeof(v));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      v[i][j] = mapa[i][j];
  nid = 0;
  memset(id, -1, sizeof(id));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (v[i][j] == '1' && id[i][j] == -1) {
	dfs(i, j);
	nid++;
      }
  //backup of id(in ID)
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ID[i][j] = id[i][j];
  
  form = 0;
  for (int _ = 0; _ < 4; _++) {
    takeinfo();
    form++;
    rotate();
  }
  inverse();
  for (int _ = 0; _ < 4; _++) {
    takeinfo();
    form++;
    rotate();
  }
  assert(form == 8);
  //  cout << "nid = " << nid << endl;
  for (int i = 0; i < nid; i++)
    stars[i].normalize();
  memset(label, 0, sizeof(label));
  char newlabel = 'a';
  for (int i = 0; i < nid; i++)
    if (label[i] == 0) {
      label[i] = newlabel;
      for (int j = i + 1; j < nid; j++)
	if (stars[i] == stars[j])
	  label[j] = newlabel;
      newlabel++;
    }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int key = ID[i][j];
      if (key != -1)
	printf("%c", label[key]);
      else
	printf("0");
    }
    printf("\n");
  }
  return 0;
}
