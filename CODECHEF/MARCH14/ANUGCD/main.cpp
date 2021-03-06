#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

char line[900000];
int now = 0;
inline int getInt(){
  int n;
  while(true)
    if(line[now] != 0){
      if(line[now] < '0' || line[now] > '9'){
        now++;
        continue;
      }
      n = 0;
      while(line[now] >= '0' && line[now] <= '9'){
        n = n * 10 + line[now] - '0';
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

#define MAXN 100010
vector<int> primes;
void generate_primes(){
  bool v[MAXN];
  fill(v, v + MAXN, false);
  for(int i = 2; i * i < MAXN; i++)
    if(!v[i])
      for(int j = i + i; j < MAXN; j += i)
        v[j] = true;
  for(int i = 2; i < MAXN; i++)
    if(!v[i])
      primes.push_back(i);
}

vector<int> fact[MAXN];
vector<int> factorize(int n){
  if(fact[n].size())return fact[n];
  vector<int> &ans = fact[n];
  int pos = 0;
  while(primes[pos] * primes[pos] <= n){
    if(n % primes[pos] == 0){
      ans.push_back(primes[pos]);
      while(n % primes[pos] == 0)
        n /= primes[pos];
    }
    pos++;
  }
  if(n > 1)ans.push_back(n);
  return ans;
}

struct SegmentTree {
  vector<int> st, A;
  int n;
  int left (int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) {
    if (L == R)
      st[p] = L;
    else {
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2])? p1 : p2;
    }
  }
  int rmq(int p, int L, int R, int i, int j) {
    if (i >  R || j <  L) return -1;
    if (L >= i && R <= j) return st[p];
    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] >= A[p2])? p1 : p2;
  }
  SegmentTree(){
    n = 0;
  }
  SegmentTree(const vector<int> &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
  int rmq(int i, int j) {
    return rmq(1, 0, n - 1, i, j);
  }
};
int n, m, g, x, y, maxnum;
int a[MAXN];
vector<int> v[MAXN];
vector<int> cont[MAXN];
SegmentTree st[MAXN];
int main(){
  generate_primes();
  n = getInt();
  m = getInt();
  maxnum = 0;
  for(int i = 0; i < n; i++){
    a[i] = getInt();
    cont[a[i]].push_back(i);
    vector<int> f = factorize(a[i]);
    for(int j = 0; j < f.size(); j++)
      v[f[j]].push_back(i);
    maxnum = max(maxnum, a[i]);
  }
  for(int i = 1; i <= maxnum; i++)
    if(v[i].size()){
      vector<int> tmp;
      for(int j = 0; j < v[i].size(); j++)
        tmp.push_back(a[v[i][j]]);
      st[i] = SegmentTree(tmp);
    }
  int ans;
  for(int i = 0; i < m; i++){
    g = getInt();
    x = getInt();
    y = getInt();
    ans = -1;
    x--; y--;
    vector<int> f = factorize(g);
    for(int j = 0; j < f.size(); j++){
      vector<int> &e = v[f[j]];
      if(e.size()){
        int pos1, pos2;
        pos1 = lower_bound(e.begin(), e.end(), x) - e.begin();
        pos2 = upper_bound(e.begin(), e.end(), y) - e.begin() - 1;
        if(pos2 - pos1 + 1 > 0)
          ans = max(ans, st[f[j]].A[st[f[j]].rmq(pos1, pos2)]);
      }
    }
    if(ans != -1)
      printf("%d %d\n", ans, upper_bound(cont[ans].begin(), cont[ans].end(), y) - lower_bound(cont[ans].begin(), cont[ans].end(), x));
    else
      puts("-1 -1");
  }
  return 0;
}
