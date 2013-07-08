#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;
string nums[103] = {"","I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX","XX","XXI","XXII","XXIII","XXIV","XXV","XXVI","XXVII","XXVIII","XXIX","XXX","XXXI","XXXII","XXXIII","XXXIV","XXXV","XXXVI","XXXVII","XXXVIII","XXXIX","XL","XLI","XLII","XLIII","XLIV","XLV","XLVI","XLVII","XLVIII","XLIX","L","LI","LII","LIII","LIV","LV","LVI","LVII","LVIII","LIX","LX","LXI","LXII","LXIII","LXIV","LXV","LXVI","LXVII","LXVIII","LXIX","LXX","LXXI","LXXII","LXXIII","LXXIV","LXXV","LXXVI","LXXVII","LXXVIII","LXXIX","LXXX","LXXXI","LXXXII","LXXXIII","LXXXIV","LXXXV","LXXXVI","LXXXVII","LXXXVIII","LXXXIX","XC","XCI","XCII","XCIII","XCIV","XCV","XCVI","XCVII","XCVIII","XCIX","C"};
int c[101]['Z'+1];

int main(){
//	freopen("entrada.in","r",stdin);
	memset(c, 0, sizeof c);
	for(int i = 1; i <= 100; ++i){
		for(int j = 'A'; j <= 'Z'; ++j)
			c[i][j] = c[i-1][j];
		for(int j = 0; j < nums[i].size(); ++j)
			c[i][nums[i][j]]++;
	}
	int n;
	while(cin >> n && n){
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, c[n]['I'],c[n]['V'],c[n]['X'], c[n]['L'],c[n]['C'] );
	}
	return 0;
}
