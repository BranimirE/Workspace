#include <iostream>
#include <vector>

using namespace std;
int solve(char a, int size, char b){
  if(size == 0)return 0;
  int ans = 0;
  if(a == 'I'){
    if(b == '*'){
      ans = ans + solve(a, size - 1, '1');
      ans = ans + solve(a, size - 1, '2');
      ans = ans + solve(a, size - 1, '*');
    }
    if(b == '0'){
      ans = ans + solve(a, size - 1, '0');
      ans = ans + solve(a, size - 1, '1');
        
    }

  }
  return ans;
}
int main(){
  
  return 0;
}
