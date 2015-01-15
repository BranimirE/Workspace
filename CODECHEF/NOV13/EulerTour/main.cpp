#include <iostream>
#include <list>
#include <vector>

using namespace std;
int ini;
vector<pair<int,int> > grafo[100];

list<int> cyc;
void EulerTour(list<int>::iterator i, int u){
  for(int j = 0; j < grafo[u].size(); j++){
    pair<int,int> v = grafo[u][j];
    if(v.second){
      v.second = 0;
      for(int k = 0; k < grafo[v.first].size(); k++){
        pair<int,int> uu = grafo[v.first][k];
        if(uu.first == u && uu.second){
          uu.second = 0;
          break;
        }
      }
      EulerTour(cyc.insert(i, u), v.first);
    }
  }
}
int main(){
  cyc.clear();
  EulerTour(cyc.begin(), ini);
  for(list<int>::iterator it = cyc.begin(); it != cyc.end(); it++)
    cout << (*it) << endl;
  return 0;
}
