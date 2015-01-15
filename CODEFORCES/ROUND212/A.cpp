#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
char m[8][11];
int dx[4] = {-2,-2, 2, 2};
int dy[4] = {-2, 2, 2,-2};

void bfs(int i, int j, int d[8][8]){
  queue<pair<int,int> > cola;
  cola.push(make_pair(i, j));
  d[i][j] = 0;
  while(!cola.empty()){
    i = cola.front().first;
    j = cola.front().second;
    cola.pop();
    for(int k = 0; k < 4; k++){
      int a = i + dx[k], b = j + dy[k];
      if(a >= 0 && a < 8 && b >= 0 && b < 8 && d[a][b] == -1){
        d[a][b] = d[i][j] + 1;
        cola.push(make_pair(a, b));
      }
    }
  }
}
int main(){
  freopen("a2.in", "r", stdin);
  int t;
  scanf("%d", &t);
  int a,b,c,d;
  a = b = c = d = -1;
  while(t--){
    a = b = c = d = -1;
    getchar();// para el '\n'
    for(int i = 0; i < 8; i++){
      gets(m[i]);
      for(int j = 0; j < 8; j++)
        if(m[i][j] == 'K'){
          if(a == -1)
            a = i, b = j;
          else
            c = i, d = j;
        }
    }
    int v1[8][8], v2[8][8];
    memset(v1, -1, sizeof(v1));
    memset(v2, -1, sizeof(v2));
    bfs(a, b, v1);
    bfs(c, d, v2);
    bool sw = false;
    for(int i = 0; i < 8 && !sw; i++)
      for(int j = 0; j < 8 && !sw; j++)
        sw = v1[i][j] != -1 && v1[i][j] == v2[i][j];
    puts(sw?"YES":"NO");
  }
  return 0;
}
