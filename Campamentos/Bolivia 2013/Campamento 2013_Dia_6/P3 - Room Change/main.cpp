#include <vector>
#include <bitset>
#include <cstdio>

#define MAXPRIME 3162300

using namespace std;

bitset<MAXPRIME> criba;
vector<long long int> primos;

void llena_criba()
{
  criba.set();
  for (int i=2; i<MAXPRIME; i++)
    if (criba.test( i ))
    {
      primos.push_back( i );
      for (int j=i+i; j<MAXPRIME; j+=i)
        criba.reset( j );
    }
}
bool solve(long long int q){
	int ans = 0, i = 0;
	while(primos[i] * primos[i] <= q){
			while(q % primos[i] == 0){
				q /= primos[i];
				ans++;
				if(ans>2)
					return false;
			}
			i++;
	}
	if(q > 1)
		ans++;
	return ans==2;
}
string g[2] = {"ANNE", "MARIAN"};
int main() {
	llena_criba();
	long long int nro ;
	while(scanf("%lld", &nro) == 1 )
		puts(g[solve(nro)].data());
	return 0;
}

