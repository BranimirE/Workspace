#include <iostream>

using namespace std;
int n, m;
long long int a,b,c,d, cant;
int main() {
  cin >> a >> b >> c >> d;
  cin >> n >> m;
  long long int buses = 0, trenes = 0;
  for(int i = 0; i < n; i++) {
    cin >> cant;
    buses += min(cant*a, b);
  }
  buses = min(buses, c);
  for(int i = 0; i < m; i++) {
    cin >> cant;
    trenes += min(cant*a, b);
  }
  trenes = min(trenes, c);
  cout << min(buses + trenes, d) << endl;
  return 0;
}
