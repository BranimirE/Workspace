#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

#define ALL(v) v.begin(),v.end()
#define SORT(v) sort(ALL(v))

using namespace std;
vector<string> v1,v2;
int main() {
    //freopen("in", "r", stdin);
    int t;
    string linea, tmp;
    cin >> t;
    getline(cin, linea);
    getline(cin, linea);
    while(t--) {
        v1.clear();
        v2.clear();
        while(getline(cin, linea) && !linea.empty())
            v1.push_back(linea);
        SORT(v1);
        for(int k = 0; k < v1.size(); k++) {
            linea = v1[k];
            tmp = "";
            for(int i = 0; i < linea.size(); i++)
                if(isalpha(linea[i]))
                    tmp = tmp + (char)linea[i];
            SORT(tmp);
            v2.push_back(tmp);
        }
        for(int i = 0; i < v1.size(); i++)
        for(int j = i + 1; j < v1.size(); j++){
            if(v2[i] == v2[j])
                cout << v1[i] << " = " << v1[j] << endl;
        }
        if(t)
            cout << endl;
    }



    return 0;
}
