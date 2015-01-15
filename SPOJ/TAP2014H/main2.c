#include <stdio.h>
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

int n, m, t, i, tail, elem, a, b;
int vec[100010];
int head[100010];
int INF = (1<<29);
int main() {
  //  scanf("%d", &t);
  t = getInt();
  while (t--) {
    //    scanf("%d", &n);
    n = getInt();
    for (i = n - 1; i >= 0; i--)
      vec[i] = getInt();
      //      scanf("%d", &vec[i]);
    head[0] = vec[0];
    tail = 1;
    for (i = 1; i < n; i++) {
      elem = vec[i];
      if (head[0] >= elem) {
	head[0] = elem;
	continue;
      }
      a = 0, b = tail;
      head[tail] = INF;
      while ((b - a) > 1) {
	m = (b + a) >> 1;
	if (head[m] < elem) a = m;
	else                b = m;
      }
      head[b] = elem;
      if (b == tail)
	tail++;
    }
    printf("%d\n", tail);
  }
  return 0;
}
