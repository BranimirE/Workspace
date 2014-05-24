#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
char c[257];
int main(){
  for(int i = 0; i < 257; i++)
    c[i] = i;
  c['c'] = c['('] = 'C';
  c['0'] = c['O'] = 'o';
  c['D'] = 'd';
  c['3'] = c['E'] = 'e';
  c['r'] = 'R';
  c['@'] = c['A'] = 'a';
  int t, size;
  string cad;
  string obj = "CodeRoad";
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    cin >> size >> cad;
    for(int i = 0; i < cad.size(); i++)
      cad[i] = c[cad[i]];
    int ans = 0;
    int pos = -1;
    while(true){
      pos = cad.find(obj, pos + 1);
      if(pos != string::npos)
        ans++;
      else
        break;
    }
    printf("Caso #%d: %d\n", caso, ans);
  }
  return 0;
}
