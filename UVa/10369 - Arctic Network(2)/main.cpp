#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct Point{
  double x, y;
  double distance(Point &other){
    return hypot(x - other.x, y - other.y);
  }
};

int satelites, n;
vector<pair<double, pair<int,int> > >edges;
Point v[505];
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> satelites >> n;
    for(int i = 0; i < n; i++)
      cin >> v[i].x >> v[i].y;
    edges.clear();
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        edges.push_back(make_pair(v[i].distance(v[j]), make_pair(i, j)));
    
  }
  return 0;
}
