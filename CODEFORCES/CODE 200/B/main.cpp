#include <iostream>

using namespace std;

int main()
{
    long long int a,b,c, d, x,y,z;
    while(cin >> a >> b >> c){
        d = (b + c) - a;
        if(a<=b+c && b <= a + c && c <= a+b && d % 2 == 0  ){
            d /= 2;
            x = b-d;
            y = d;
            z = c-d;
            cout << x << " " << y << " " << z<< endl;
        }else
            cout << "Impossible" << endl;
    }
    return 0;
}
