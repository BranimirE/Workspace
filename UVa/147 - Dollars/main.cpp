#include <cstdio>

#define MAX 30005
using namespace std;
int v[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned long long int dp[MAX + 1] = {0}, c;
int main() {
  dp[0] = 1;
  for(int i = 0; i < 11; i++) {
    for(int j = v[i]; j <= MAX; j++)
      dp[j] += (dp[j-v[i]]);
  }
  int i, d;
  scanf("%d.%d", &i, &d);
  while(i || d){
    printf("%3d.%.2d%17llu\n", i, d, dp[i*100 + d]);
    scanf("%d.%d",&i,&d);
  }
  return 0;
}
