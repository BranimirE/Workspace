#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
double a[12];

#define PI acos(-1)

int n;
double abajo,arriba,incr;
double f(double x){
	double ans = 0;
	for(int i = 0; i <= n; i++)
		ans += (a[i] * pow(x,i));
	return ans*ans*PI;
}
double S(double a, double b, double c, double h){
	return (h / 3.0) * ( f(a) + 4.0 * f(c) + f(b));
}
double SIMP(double a, double b, double E ){
	double h = (b-a)/2.0,
	       c = (b+a)/2.0;

	double a1 = a,  b1 = c,
	       a2 = c,  b2 = b;

	double c1 = (b1+a1)/2.0, 
	       c2 = (b2+a2)/2.0;

	double L = (S(a1,b1, c1,h) + S(a2,b2,c2,h)) / 2.0;
	if(0.1*abs(L-S(a,b,c,h)) < E)
		return L;
	else
		return SIMP(a1,b1, E/2.0) + SIMP(a2,b2, E/2.0);
}
double buscar(double izq, double der, double obj){

	double med, ini = izq;
	izq = abajo, der = arriba;
	while(izq < der){
		med = (izq + der) / 2.0;

		double vtmp = SIMP(ini, med, 0.0000001);

		if(obj < vtmp)
			der = med - 0.0000001;
		else
			izq = med + 0.0000001;
	}
	if(abs(SIMP(ini, izq, 0.0000001)-obj) < 0.001)
		return izq-ini;
	return -1;
}
int main(){
	freopen("entrada.in","r",stdin);
	int caso = 1;

	while(cin >> n){
		for(int i = 0; i <= n; ++i)
			cin >> a[i];
		cin >> abajo >> arriba >> incr;
		double vol = SIMP(abajo, arriba, 0.001);
	
		printf("Case %d: %.2f\n",caso, vol);
		bool nsp = true;
		for(double inc = incr; inc <= 8*incr; inc += incr){
			double ans = buscar(abajo, arriba, inc);
			if(ans != -1){
				if(!nsp)
					cout << " ";
				printf("%.2f",ans);
				nsp = false;
			}else
				break;
		}
		if(nsp)
			cout << "insufficient volume" ;
		cout << endl;

		caso++;
	}
	return 0;
}
