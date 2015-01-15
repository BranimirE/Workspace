#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int k;
    vector<int> Y;
    while(scanf("%d", &k) == 1){
        Y.clear();
        for(int y = k + 1; y <= 2*k; y++)
            if((y*k)%(y-k) == 0)
                Y.push_back(y);
        printf("%d\n", Y.size());
        for(int i = 0; i < Y.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n",k,(Y[i]*k)/(Y[i]-k), Y[i]);
    }
    return 0;
}
