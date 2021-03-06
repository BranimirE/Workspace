#include <bits/stdc++.h>

using namespace std;
int n;
bool tab[10][10];
bool haysolucion;
void imprimirSolucion(){
    if(haysolucion)
      cout << endl;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(j)cout << '\t';
        if(tab[i][j])
          cout << 'Q';
        else
          cout << '-';
      }
      cout << endl;
    }
}
bool puedoponer(int fil, int col){
  //Recorro hacia atras en las columnas
  for(int j = col - 1; j >= 0; j--){
    if(tab[fil][j])                      //Verifico fila
      return false;

    int i = col - j;//distancia
    if((fil - i) >= 0 && tab[fil - i][j])// Diagonal hacia arriba
      return false;

    if((fil + i) < n && tab[fil + i][j]) // Diagonal hacia abajo
      return false;
  }
  return true;
}
void solve(int col){
  if(col == n){              //Es solucion!!!
    imprimirSolucion();
    haysolucion = true;
    return;
  }
  for(int fil = 0; fil < n; fil++){    
    if(puedoponer(fil, col)){
      tab[fil][col] = true;  //Pongo
      solve(col + 1);        //Intento poner en la sig columna
      tab[fil][col] = false; //Pruebo las otras filas
    } 
  }
}
int main(){
  while(cin >> n){
    haysolucion = false;
    memset(tab, false, sizeof(tab));
    solve(0);
    if(!haysolucion)
      cout << "Not Possible" << endl;
  }
  return 0;
}
