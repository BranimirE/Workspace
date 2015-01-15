#include <cstdio>

using namespace std;

char line[400000];//OJO maximo mas 3 para el '\n' y el '\0'
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
