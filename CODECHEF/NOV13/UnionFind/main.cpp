#include <cstdio>
#include <vector>
#define MAX 100000
using namespace std;
struct UnionFind{
  int p[MAX], r[MAX], setSize[MAX];
  int n, numSets;
  UnionFind(int _N){
    reset(_N);
  }
  void reset(int N){
    n = N;
    numSets = n;
    for(int i = 0; i <= n; i++){
      p[i] = i;
      r[i] = 0;
      setSize[i] = 1;
    }
  }
  int Find(int i){return (p[i] == i)?i:(p[i] = Find(p[i]));}
  bool sameComponent(int i, int j){return Find(i) == Find(j);}
  void Union(int i, int j){
    if(!sameComponent(i, j)){
      numSets--;
      int x = Find(i), y = Find(j);
      if(r[x] > r[y]){
        p[y] = x;
        setSize[x] += setSize[y];
      } else                   {
        p[x] = y;
        setSize[y] += setSize[x];
        if (r[x] == r[y]) r[y]++;
      }
    }
  }
  int numDisjointSets(){
    return numSets;
  }
  int sizeOfSet(int i){
    return setSize[Find(i)];
  }
};

int main() {
  printf("Assume that there are 5 disjoint sets initially\n");
  UnionFind UF(5); // create 5 disjoint sets
  printf("%d\n", UF.numDisjointSets()); // 5
  UF.Union(0, 1);
  printf("%d\n", UF.numDisjointSets()); // 4
  UF.Union(2, 3);
  printf("%d\n", UF.numDisjointSets()); // 3
  UF.Union(4, 3);
  printf("%d\n", UF.numDisjointSets()); // 2
  printf("sameComponent(0, 3) = %d\n", UF.sameComponent(0, 3)); // will return 0 (false)
  printf("sameComponent(4, 3) = %d\n", UF.sameComponent(4, 3)); // will return 1 (true)
  for (int i = 0; i < 5; i++) // Find will return 1 for {0, 1} and 3 for {2, 3, 4}
    printf("Find(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.Find(i), i, UF.sizeOfSet(i));
  UF.Union(0, 3);
  printf("%d\n", UF.numDisjointSets()); // 1
  for (int i = 0; i < 5; i++) // Find will return 3 for {0, 1, 2, 3, 4}
    printf("Find(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.Find(i), i, UF.sizeOfSet(i));
  return 0;
}
