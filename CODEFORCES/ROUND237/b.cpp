#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
  double dist, side, pos;
  int n;
  scanf("%lf %lf", &side, &dist);
  scanf("%d", &n);
  pos = 0;
  for(int i = 1; i <= n; i++){
    pos += dist;
    pos = fmod(pos, side * 4.0);
    double x, y;
    if(pos <= side){
      x = pos;
      y = 0;
    }else if(pos <= side * 2.0){
      x = side;
      y = pos - side;
    }else if(pos <= side * 3.0){
      x = side - (pos - side - side);
      y = side;
    }else{
      x = 0;
      y = side - (pos - side - side - side);
    }
    printf("%.10lf %.10lf\n", x, y);
  }
  return 0;
}
