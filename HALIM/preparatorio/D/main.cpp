#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

#define MAX 105
int cap[MAX][MAX], padre[MAX], n, s, t;
 
bool bfs() {
    queue<int> q;
    q.push(s);
    memset(padre, -1, sizeof padre);
    padre[s] = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return true;
        for (int v = 0; v < n; v++)
            if (padre[v] == -1 && cap[u][v])
                padre[v] = u, q.push(v);
    }
    return false;
}
 
int maxFlow() {
    int mf = 0, f, v;
    while (bfs()) {
        v = t;
        f = INT_MAX;
        while (padre[v] != v)
            f = min(f, cap[padre[v]][v]), v = padre[v];

        v = t;
        mf += f;
        while (padre[v] != v)
            cap[padre[v]][v] -= f, cap[v][padre[v]] += f, v = padre[v];
    }
    return mf;
}
 
int main() {
  int a, b;
  while((cin >> n >> a >> b) && !(a == 0 && b == 0 && n == 0)){
    memset(cap, 0, sizeof(cap));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> cap[i][j];
    s = n++;
    t = n++;
    while(a--){
      int tosea;
      cin >> tosea;
      cap[tosea][t] = cap[tosea][t] = 1000000;
    }
    int total = 0;
    while(b--){
      int rain, quantity;
      cin >> rain >> quantity;
      cap[s][rain] = cap[rain][s] = quantity;
      total += quantity;
    }
    int mf = maxFlow();
    if(mf >= total)
      cout << "SAFE" << endl;
    else
      cout << "FLOOD!!!" << endl;
  }
  return 0;
}
