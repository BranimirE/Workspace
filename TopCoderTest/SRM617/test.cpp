#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <cmath>
typedef long long int Number;
using namespace std;
bool isPrime(int n){
  if(n % 2 == 0)
    return n == 2;

  int div = 3;
  while(div * div <= n){
    if(n % div == 0)
      return false;
    div += 2;
  }
  return true;
}
vector<Number> primes;
  void generatePrimes(){
    primes.push_back(2);
    for(int i = 3; i <= 32000; i++)
      if(isPrime(i))
        primes.push_back(i);
  }
  vector<pair<Number, int> > factorize(Number n){
    int i = 0;
    map<Number, int> fac;
    while(primes[i] * primes[i] <= n){
while(n % primes[i] == 0){
        fac[primes[i]]++;
n/=primes[i];
}
      i++;
    }
    if(n > 1)
      fac[n]++;
    return vector<pair<Number, int> >(fac.begin(), fac.end());
  }
 vector<pair<Number, int> > f;
  set<Number> d;
  int cant[200];
  void generateDivisors(int i){

    if(i == f.size()){
      Number div = 1;
      for(int j = 0; j < f.size(); j++)
        div *= pow(f[j].first, cant[j]);
      d.insert(div);

      return;
    }
    for(int j = 0; j <= f[i].second; j++){
      cant[i] = j;
      generateDivisors(i + 1);
    }
  }
int main(){
generatePrimes();
cout << "asdf" << endl;
f = factorize(12);
for(int i = 0; i < f.size(); i++)
  cout << f[i].first << " " << f[i].second << endl;
set<Number>::iterator it;
generateDivisors(0);
for(it = d.begin(); it != d.end(); it++)
cout << (*it) << endl;
return 0;
}
