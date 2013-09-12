#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> A, B;

void subsets(vector<long long int> v, vector<long long int> &ans) {
    ans.clear();
    int n = v.size();
    for(int mask = 0; mask < (1<<n); mask++) {
        long long int sum = 0;
        for(int j = 0; j < v.size(); j++)
            if(mask & (1<<j))
                sum += v[j];
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
}

int main() {
    int N,n;
    long long int sum;
    while(scanf("%d%lld", &N, &sum) == 2) {
        vector<long long int> v(N);
        for(int i = 0; i < N; i++)
            scanf("%lld", &v[i]);
        n = N / 2;
        subsets(vector<long long int>(v.begin(), v.begin()+n), A);
        subsets(vector<long long int>(v.begin()+n, v.end()), B);
        n = B.size();
        long long ans=0;
        for(int i = 0; i < A.size(); i++)
            if(A[i] <= sum) {
                ans =  max(ans, A[i]);
                long long int val = sum - A[i];
                int j = lower_bound(B.begin(), B.end(), val) - B.begin();
                if(j < n && B[j] == val) {
                    ans = sum;
                    break;
                } else
                    ans = max(ans, A[i] + B[j-1]);
            }
        printf("%lld\n", ans);
    }
    return 0;
}

