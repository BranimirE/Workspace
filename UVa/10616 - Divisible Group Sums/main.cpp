#include <iostream>

using namespace std;
int vec[5] = {0};
int main() {
    for(int mask = 0; mask < (1 << 10); mask++){
      int sum = 0;
      for(int i = 0; i < 10; i++)
        if(mask&(1<<i))
          sum += (i + 1);
      vec[sum%5]++;
    }
    for(int i = 0; i < 5; i++)
      cout << " " << vec[i] ;
    cout << endl;
    return 0;
}
