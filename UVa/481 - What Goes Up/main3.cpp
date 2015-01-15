#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long int> v;
vector<int> p;
vector<int> dp;
int lis(int i){
  if(i == 0)return 1;

  int &ans = dp[i];
  if(ans != -1)return ans;
  ans = 1;
  for(int j = 0; j < i; j++)
    if(v[j] < v[i]){
      int tmp = 1 + lis(j);
      if(tmp > ans){
        ans = tmp;
        p[i] = j;
      }
    }
  return ans;
}

int main()
{
  puts("sol 2");
    long long int tmp;
    while(scanf("%lld", &tmp) == 1)
      v.push_back(tmp);
    int n = v.size(), ans = 0, ultimo = n - 1;
    p.resize(n, -1);
    dp.resize(n, -1);
    for(int k = 0; k < n; k++){
      int tmp = lis(k);
      if(tmp >= ans){
        ans = tmp;
        ultimo = k;
      }
    }
    printf("%d\n", ans);
    puts("-");
    // imprimir secuencia
    vector<long long int> sol;
    do{
      sol.push_back(v[ultimo]);
      ultimo = p[ultimo];
    }while(ultimo != -1);
    for(int i = sol.size()-1; i >= 0; i--)
      printf("%lld\n",sol[i]);
    return 0;
}

