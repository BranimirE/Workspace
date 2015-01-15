#include <iostream>
#include <vector>

using namespace std;

int fil, col;
vector<pair<int,int> > g[10005];
int ady[10005],tmp;
int main()
{

    while(cin >> fil >> col){
        for(int i = 1; i <= col; i++)
            g[i].clear();

        for(int i = 1; i <= fil; i++){
            int nad;
            cin >> nad;

            for(int j = 0; j < nad; j++)
                cin >> ady[j];
            for(int j = 0; j < nad; j++){
                cin >> tmp;
                g[ady[j]].push_back(make_pair(i,tmp));
            }
        }
        cout << col << " " << fil << endl;
        swap(col,fil);
        for(int i = 1; i <= fil; i++){
            cout << g[i].size();
            for(int j = 0; j < g[i].size(); j++)
                cout <<" "<< g[i][j].first;
            cout << endl;

            for(int j = 0; j < g[i].size(); j++)
                cout <<(j?" ":"")<< g[i][j].second;
            cout << endl;
        }
    }
    return 0;
}
