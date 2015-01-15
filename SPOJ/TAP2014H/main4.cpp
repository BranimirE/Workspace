#include <cstdio>
#include <set>

using namespace std;
char line[700010];//OJO maximo mas 3 para el '\n' y el '\0'
int now = 0;
inline int getInt(){
  int n;
  while(1)
    if (line[now] != 0) {
      if(line[now] < '0' || line[now] > '9') {
	now++;
	continue;
      }
      n = 0;
      while(line[now] >= '0' && line[now] <= '9') {
	n = n*10 + line[now] - '0';
	now++;
      }
      return n;
    }
    else {
      gets(line);
      now = 0;
    }
  return n;
}

int n;
int vec[100010];
set<int> lis;
set<int>::iterator it;

int main() {
  int t;
  // scanf("%d", &t);
  t = getInt();
  while (t--) {
    //    scanf("%d", &n);
    n = getInt();
    for (int i = n - 1; i >= 0; i--)
      vec[i] = getInt();
      //      scanf("%d", &vec[i]);
    lis.clear();
    for (int i = 0; i < n; i++) {
      lis.insert(vec[i]);
      it = lis.find(vec[i]);
      it++;
      if (it != lis.end())
	lis.erase(it);
    }
    printf("%d\n", lis.size());
  }
  return 0;
}
