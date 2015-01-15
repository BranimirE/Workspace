/*
ID: brani.e2
PROG: wormhole
LANG: C++
 */
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>


using namespace std;
int x[20], y[20];
int match[20];
int n;
vector<int> gg[20];
int g[20][20];
bool color[20];
int ans;
const int white = 0, gray = 1, black = 2;
bool findcycle(int u, int p) {
  
  cout << "entra " << u << " -> padre "  << p << endl;
  color[u] = gray;
  bool cycle = false;
  for (int v = 0; v < n && !cycle; v++) {

    if (v == p && g[u][v] == 2){
      cout << "INFINITY" << endl;
      return true;
    }
    
    if (v != p  && g[u][v]>0 && color[v] != black) {
    if (u == 3)
      cout << "3 VISITA A = " << v << "color de 2 en este = " << color[v] << endl;
    
      if (color[v] == white) {
	cycle |= findcycle(v, u);
	if (cycle)cout << "OP1" << endl;
      } else {
	cycle = true;
	if (cycle)cout << "OP2" << endl;	
      }
      if (cycle) {
	cout << "termino ciclo en = " << u << " -> " << v << " color del fin = "<< color[v] <<  endl;
      }
    }
  }
  if (u == 2)
    cout << "MAAAAAAAAAAAAAAAAAAARCA 2" << endl;
  color[u] = black;
  return cycle;
}
void generateMatch(int pairs) {
  if ((pairs<<1) == n) {
    memset(g, 0, sizeof(g));
    bool istherecycle = false;
    for (int i = 0; i < n; i++) {
      g[i][match[i]] = 1;
      for (int j = 0; j < gg[i].size(); j++) {
	g[i][gg[i][j]] = 2;//Arco de a pie
	//cout << "marca de " << i << " a " << gg[i][j] << endl;
      }
    }

    for (int i = 0; i < n && !istherecycle; i++) {
      memset(color, white, sizeof(color));
      //cout << "llama findcycle" << endl;
      cout << "INI = " << i << endl;
      istherecycle |= findcycle(i, -1);
      if (istherecycle)
	cout << "HEEEEEEEEEEERE" << endl;
    }

    cout <<string(10, '-') <<  "MATCH"<< string(10, '-') << endl;
    for (int i = 0; i < n; i++) {
      cout << i << " - " << match[i] << endl;
    }
    if (istherecycle)
      ans++;
    cout << "Graph" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	cout << g[i][j] << " ";
      }
      cout << endl;
    }
      
    cout <<"cycle = " << istherecycle << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (match[i] == -1) {
      for (int j = i + 1; j < n; j++) {
	if (match[j] == -1) {
	  match[i] = j;
	  match[j] = i;
	  generateMatch(pairs + 1);
	  match[i] = match[j] = -1;
	}
      }
      return;
    }
  }
}
int main() {
  //  freopen("wormhole.in", "r", stdin);
  //freopen("wormhole.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  for (int i = 0; i < n; i++) {
    int e = -1;
    for (int j = 0; j < n; j++) {
      if (y[i] == y[j] && x[j] > x[i]) {
	if (e == -1 || x[j] < x[e]) {
	  e = j;
	}
      }
    }
    if (e != -1) {
      gg[i].push_back(e);
    }
  }
  cout << "pre graph" << endl;
  for (int i = 0; i < n; i++) {
    cout << "g[" << i << "] : ";
    for (int j = 0; j < gg[i].size(); j++) {
      cout << gg[i][j] << " ";
    }
    cout << endl;
  }
  memset(match, -1, sizeof(match));
  ans = 0;
  generateMatch(0);
  printf("%d\n", ans);
  return 0;
}

