#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN 100010
struct Solve{
  int vec[MAXN];
  int n;
  int sig[MAXN];

  int size[MAXN];
  int INI, FIN;
  Solve(int _n) {
    n = _n;
    memset(sig, -1, sizeof(sig));
    memset(size, 0, sizeof(size));
    sig[1] = -1;
    size[1] = n;
    INI = 1;
    FIN = 1;
    
  }
  void readData() {
    forn (i, n)
      scanf("%d", &vec[i + 1]);
  }
  //returns (index of group, index in the group)
  pair<int,int> getGroup(int i) {    
    int cur = INI;
    while (cur != -1) {
      if (i <= size[cur])
	return mp(cur, i);
      i -= size[cur];
      cur = sig[cur];
    }
    assert(true);
    return mp(-1, -1);
  }
  int operator [] (int index) {
    pair<int,int> tmp = getGroup(index);
    int group = tmp.first;
    int element = tmp.second;
    return vec[group + element - 1];
  }
  void swapgroups(int groupA, int groupB) {
    sig[FIN] = INI;
    INI = groupB;
    FIN = groupA;
    sig[FIN] = -1;
  }
  void rotate(int index) {
    if (index == n || index == 0) return;
    pair<int,int> tmp = getGroup(index);
    int groupA = tmp.first;
    int elementA = tmp.second;
    //    tmp = getGroup(index + 1);
    int groupB = tmp.first;
    int elementB = tmp.second + 1;
    if (elementB > size[groupA]) {
      groupB = sig[groupA];
      elementB = 1;
    }
      
    if (groupA != groupB) {
      swapgroups(groupA, groupB);
    }else {
      int nuevo = groupA + elementA;
      sig[nuevo] = sig[groupA];
      size[nuevo] = size[groupA] - elementA;
      sig[groupA] = nuevo;
      size[groupA] = elementA;
      
      if (FIN == groupA)
	FIN = nuevo;
      swapgroups(groupA, nuevo);
    }
  }
    void mostrar() {
    int cur = INI;
    while(cur != -1) {
      for (int i = cur; i < cur + size[cur]; i++)
	cout << vec[i] << " ";
      cout << " - ";
      cur = sig[cur];
    }
    cout << endl;
    cout << string(15,'-') << endl;
    cout << " INI = " << INI << endl;
    cout << " FIN = " << FIN << endl;
    for (int i = 1; i <= n; i++)
      printf("%4d", i);
    printf("\n");

    for (int i = 1; i <= n; i++)
      printf("%4d", sig[i]);
    printf("\n");

    for (int i = 1; i <= n; i++)
      printf("%4d", size[i]);
    printf("\n");
    cout << string(15,'-') << endl;
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Solve s(n);
  s.readData();
  char op;
  int ind;
  char buf[20];
  gets(buf);
  while(m--) {
    gets(buf);
    sscanf(buf, "%c %d", &op, &ind);
    if (op == 'R')
      printf("%d\n", s[ind]);
    if (op == 'C')
      s.rotate(ind);
    if (op == 'A')
      s.rotate(n - ind);
  }
  return 0;
}
