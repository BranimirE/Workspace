#include <bits/stdc++.h>

using namespace std;
vector<double> x, y, r;
int n;
int main(){
  int cases;
  scanf("%d",&cases);
  while(cases--){
    x.clear();
    y.clear();
    r.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      double X, Y, R;
      scanf("%lf%lf%lf", &X, &Y, &R);
      x.push_back(X);
      y.push_back(Y);
      r.push_back(R);
    }
    double ans = 1000/2.0;
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++){
        double dist = hypot(x[i]-x[j], y[i] - y[j]);
        ans = min(ans, (dist - r[i] - r[j])/ 2.0);
      }
    printf("%lf\n", ans);
  }
  return 0;
}
