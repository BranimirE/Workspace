/*
ID: brani.e2
PROG: combo
LANG: C++
 */
#include <cstdio>
#include <set>
using namespace std;

typedef pair<int, pair<int, int> > config;
#define x first
#define y second.first
#define z second.second


int N;
set<config> myset;
void process(config initial) {
  initial.x--; initial.y--; initial.z--;
  for (int i = initial.x - 2 ; i <= initial.x + 2; i++) {
    int a = (i + N) % N;
    for (int j = initial.y - 2; j <= initial.y + 2; j++) {
      int b = (j + N) % N;
      for (int k = initial.z - 2; k <= initial.z + 2; k++) {
	int c = (k + N) % N;
	myset.insert(config(a, make_pair(b, c)));
      }
    }
  }
}
int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out","w", stdout);
  scanf("%d", &N);
  config a, b;
  scanf("%d %d %d", &a.x, &a.y, &a.z);
  scanf("%d %d %d", &b.x, &b.y, &b.z);
  process(a);
  process(b);
  printf("%d\n", int(myset.size()));
  return 0;
}
