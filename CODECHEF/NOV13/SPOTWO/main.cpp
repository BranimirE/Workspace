#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>

#define MOD 1000000007ULL
#define LIM 4294967295ULL
using namespace std;
char line[30];
int now = 0;
inline int getInt(){
	int n;
	while(1)
		if(line[now]!=0){
			if(line[now]<'0' || line[now]>'9'){
				now++;
				continue;
			}
			n = 0;
			while(line[now]>='0' && line[now]<='9') {
				n = n*10 + line[now] - '0';
				now++;
			}
			return n;
		}
		else{
			gets(line);
			now = 0;
		}
	return n;
}
bool cad[70];
int tam;
unsigned long long int tobinary(int n){
  tam = 0;
  while(n){
    cad[tam++] = (n & 1);
    n >>= 1;
  }
  unsigned long long int ans = 0;
  for(int i = tam - 1; i >= 0; i--){
    ans *= 10ULL;
    if(cad[i])
      ans += 1ULL;
  }
  return ans;
}

unsigned long long int multi(unsigned long long a, unsigned long long b, unsigned long long mod){
	if(b == 0) return 0;
	if(a <= LIM && b <= LIM){
    unsigned long long int tmp = a * b;
    if(tmp >= mod)
      tmp %= mod;
    return tmp;
	}
	unsigned long long int ans = (multi( a, b >> 1ULL, mod ) << 1ULL) % mod;
	if( b & 1 ) ans = (ans + a) % mod;
	return ans;
}

unsigned long long int solve(unsigned long long int e){
  if(e <= 60ULL) return (1ULL << e);
  unsigned long long int tmp = solve(e >> 1ULL);
  //tmp = (tmp * tmp) % MOD;
  tmp = multi(tmp, tmp, MOD);
  if(e & 1ULL)
    tmp = (tmp << 1ULL) % MOD;
  return tmp;
}

int main(){
  freopen("in", "r", stdin);
  int t, n;
  //scanf("%d", &t);
  t = getInt();
  while(t--){
    //scanf("%d", &n);
    n = getInt();
    unsigned long long int tmp = solve(tobinary(n));
    //tmp = (tmp*tmp) % MOD;
    tmp = multi(tmp, tmp, MOD);
    printf("%llu\n", tmp);
  }
  return 0;
}
