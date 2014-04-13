#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
int filas, cols, bombas;
int g[100][100];
bool isValid(int i, int j){
  return i >= 0 && i < filas && j >= 0 && j < cols;
}
bool v[100][100];
void dfs(int i, int j){
  if(v[i][j]) return;
  v[i][j] = true;
  if(g[i][j] == 0)
    for(int ii = i - 1; ii <= i + 1; ii++)
      for(int jj = j - 1; jj <= j + 1; jj++)
        if(isValid(ii, jj))
          dfs(ii, jj);
}
int main(){
  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    cin >> filas >> cols >> bombas;
    int cant = filas * cols;
    int free = cant - bombas;
    printf("Case #%d:\n", caso);
    if(free == 1){
      for(int i = 0; i < filas; i++)
        if(i == 0)
          cout << "c" << string(cols - 1, '*') << endl;
        else
          cout << string(cols, '*') << endl;
      continue;
        
    }
    int sol = -1;
    
    for(int mask = 0; mask < (1 << cant); mask++){
      int bomb = __builtin_popcount(mask);
      if(bomb == bombas){
        
        memset(g, 0, sizeof(g));
        int pos = 0;
        for(int i = 0; i < filas; i++)
          for(int j = 0; j < cols; j++){
            if((1 << pos) & mask)
              for(int ii = i - 1; ii <= i + 1; ii++)
                for(int jj = j - 1; jj <= j + 1; jj++)
                  if(isValid(ii, jj))
                    g[ii][jj]++;
            pos++;
          }
       

        bool sw = false;
        for(int i = 0; i < filas; i++)
          for(int j = 0; j < cols; j++){
            if(g[i][j] == 0){
              memset(v, false, sizeof(v));
              dfs(i, j);
              sw = true;
              break;
            }
          }
        
        if(sw == true){
          int vis = 0;
          for(int i = 0; i < filas; i++)
            for(int j = 0; j < cols; j++)
              vis += v[i][j];
          
          if(vis == cant - bomb){
            sol = mask;
            goto continuar;
          }
        }
      }
    }
  continuar:

   
    if(sol != -1){
    
      bool sw = true;
      int pos = 0;
      for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
          if(sol & (1 << pos))
            cout << "*";
          else{
            if(g[i][j] == 0 && sw){
              sw = false;
              cout << "c";
            }
            else
              cout << ".";
          }
          pos++;
        }
        cout << endl;
      }
    }else
      cout << "Impossible" << endl;      
  }
  return 0;
}
