#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double p, q, r, s, t, u;
double F(double x){
	double ans = 0;
	ans = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
	return ans;
}
int main(){
	double delta = 0.000000001;
	while(cin >> p >> q >> r >> s >> t >> u ){
		double l, r;
		l = 0;
		r = 1;
		int cantidad = 100;
		while(l < r && cantidad){
			cantidad--;
			double m = (l+r)/2.0;
			//cout << " Prueba con " << m << endl;
			double val = F(m);
			if(val < 0)
				r = m ;
			else
				l = m ;
		}
		double fx = F(l);

		if(l>=0 && l <= 1 && abs(fx) < 0.00000000001)
			printf("%.4lf\n", l );
		else
			puts("No solution");
	}
	return 0;
}
