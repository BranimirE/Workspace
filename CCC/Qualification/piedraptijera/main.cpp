#include <iostream>
#include <cstring>

#define piedra 'I'
#define papel 'A'
#define tijera 'T'
#define angela 1
#define bernardo 2
using namespace std;
int game['T' + 1]['T' + 1];
int main(){
  memset(game, 0, sizeof(game));
  game[piedra][tijera] = angela;  game[tijera][piedra] = bernardo;
  game[tijera][papel]  = angela;  game[papel][tijera]  = bernardo;
  game[papel][piedra]  = angela;  game[piedra][papel]  = bernardo;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string g;
    cin >> g;
    int wins[3] = {0};
    for(int i = 0; i < g.size(); i += 2)
      wins[game[g[i]][g[i+1]]]++;
    if(wins[angela] > wins[bernardo])
      cout << "Angela gana" << endl;
    else if(wins[bernardo] > wins[angela])
      cout << "Bernardo gana" << endl;
    else
      cout << "Empate" << endl;
  }
  return 0;
}
