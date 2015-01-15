
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
    string c = "", tmp;
    int n, ans;
    cin >> n;
    while(n--){
        cin >> tmp;
        c = c + tmp;
    }
    ans = 1;
    for(int i = 1; i < c.size(); i++)
        if(c[i] == c[i-1])
            ans++;
    cout << ans << endl;
    return 0;
}
