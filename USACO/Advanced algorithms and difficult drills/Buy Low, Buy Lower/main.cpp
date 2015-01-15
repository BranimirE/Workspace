/*
 ID: brani.e2
 PROG: buylow
 LANG: C++
*/
#include <bits/stdc++.h>
#define MAX 5005
using namespace std;
typedef long long int Number;
struct BigNumber{
  char v[100];
  int size;
  BigNumber(Number num = 0){
    memset(v, 0, sizeof(v));
    if(num == 0)
      size = 1;
    else{
      size = 0;
      while(num){
        v[size++] = num % 10;
        num /= 10LL;
      }
    }
  }
  BigNumber operator + (BigNumber o){
    BigNumber ans;
    int carry = 0;
    ans.size = 0;
    for(int i = 0, lim = max(size, o.size); i < lim; i++){
      carry = carry + v[i] + o.v[i];
      ans.v[ans.size++] = carry % 10;
      carry /= 10;
    }
    while(carry){
      ans.v[ans.size++] = carry % 10;
      carry /= 10;
    }
    return ans;
  }
  string toString(){
    string ans = "";
    for(int i = size - 1; i >= 0; i--)
      ans.push_back('0' + v[i]);
    return ans;
  }
};

int n;
Number v[MAX], cp[MAX];
pair<int, BigNumber> memo[MAX];
bool dp[MAX];

pair<int, BigNumber> solve(int pos){
  if(dp[pos])return memo[pos];
  
  int ans = 1;
  for(int i = pos + 1; i < n; i++)
    if(v[i] > v[pos])
      ans = max(ans, 1 + solve(i).first);
  if(ans == 1){
    dp[pos] = true;
    return memo[pos] = make_pair(1, 1);
  }

  bool inset[MAX];
  memset(inset, false, sizeof(inset));
  BigNumber count;
  for(int i = pos + 1; i < n; i++)
    if(v[i] > v[pos]){
      pair<int, BigNumber> tmp = solve(i);
      if(ans == (tmp.first + 1))
        if(inset[v[i]] == false){
          inset[v[i]] = true;
          count = count + tmp.second;
        }
    }
  dp[pos] = true;
  return memo[pos] = make_pair(ans, count);
}

int main(){
  freopen("buylow.in", "r", stdin);
  freopen("buylow.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld", &v[i]);
    cp[i] = v[i];
  }
  sort(cp, cp + n);
  map<Number, int> id;
  int assign = 0;
  id[cp[0]] = assign++;
  for(int i = 1; i < n; i++)
    if(cp[i] != cp[i - 1])
      id[cp[i]] = assign++;
  for(int i = 0; i < n; i++)
    v[i] = id[v[i]];
  reverse(v, v + n);

  memset(dp, false, sizeof(dp));
  int ans = 0;
  BigNumber count = 0;
  for(int i = 0; i < n; i++)
    ans = max(ans, solve(i).first);
  set<Number> inset;
  for(int i = 0; i < n; i++){
    pair<int, BigNumber> tmp = solve(i);
    if(tmp.first  == ans && !inset.count(v[i])){
      inset.insert(v[i]);
      count = count + tmp.second;
    }
  }
  cout << ans << " " << count.toString() << endl;
  return 0;
}
