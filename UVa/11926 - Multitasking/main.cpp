#include <iostream>
#include <bitset>

using namespace std;
bitset<1000001> bs;
int main() {
    int n,m,a,b,c;
    while(cin >> n >> m, !(n==0 && m==0)) {
        bool update = true;
        bs.reset();
        while(n--) {
            cin >> a >> b;
            if(update)
                while(a < b) {
                    if(bs[a]) {
                        update = false;
                        break;
                    } else
                        bs[a] = true;
                    a++;
                }
        }
        while(m--) {
            cin >> a >> b >> c;
            int res = b - a;
            if(update)
                for(int A = a; A < 1000000; A += c) {
                    a = A;
                    b = a + res;
                    while(a < b) {
                        if(bs[a]) {
                            update = false;
                            break;
                        } else
                            bs[a] = true;
                        a++;
                    }
                }
        }
        if(update)
            cout << "NO CONFLICT" << endl;
        else
            cout << "CONFLICT" << endl;
    }
    return 0;
}
