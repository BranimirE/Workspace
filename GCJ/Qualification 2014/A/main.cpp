#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
  int t;
  cin >> t;
  bool sw[20], sw2[20];
  for(int caso = 1; caso <= t; caso++){
    int a, b, tmp;

    memset(sw, false, sizeof(sw));
    memset(sw2, false, sizeof(sw2));
    cin >> a;
    for(int f = 1; f <= 4; f++)
      for(int c = 1; c <= 4; c++){
        cin >> tmp;
        if(f == a)
          sw[tmp] = true;
      }     
    
    cin >> b;
    for(int f = 1; f <= 4; f++)
      for(int c = 1; c <= 4; c++){
        cin >> tmp;
        if(f == b && sw[tmp])
          sw2[tmp] = true;          
      }

    int cant = 0;
    int sol = -1;
    for(int i = 1; i <= 16; i++)
      if(sw2[i]){
        cant++;
        sol = i;
      }
    if(cant == 1)
      printf("Case #%d: %d\n", caso, sol);
    else if(cant > 1)
      printf("Case #%d: Bad magician!\n", caso);
    else
      printf("Case #%d: Volunteer cheated!\n", caso);
  }
  return 0;
}
