#include <stdio.h>

typedef unsigned long long int Number;
Number contar(Number n){
	Number ans = 0, tmp = n, doble, unos;
	n++;
	for(unos = 1; tmp; unos *= 2ULL, tmp /= 2ULL){
		doble = unos * 2ULL;
		Number tmp = ((n / doble) * unos);
		if((n % doble) > unos)
			tmp += n % doble - unos;
		ans = ans + tmp;
	}
	return ans;
}
char c[100];
Number a, b;
int leer(){
	if(gets(c)){
		int i = 0;
		a = b = 0;
		while(c[i] != ' ')
			a = a * 10 + c[i++] - '0';
		i++;
		while(c[i])
			b = b * 10 + c[i++] - '0';
		return 1;
	}
	return 0;
}
int main() {

	while(leer())
		printf("%llu\n", contar(b) - contar(a-1));
	return 0;
}
