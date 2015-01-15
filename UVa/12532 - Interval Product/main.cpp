#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
private:
    vi st, A;            // recall that vi is: typedef vector<int> vi;
    int n;
    int left (int p) {
        return p << 1;
    }
    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {                           // O(n log n)
        if (L == R)                            // as L == R, either one is fine
            st[p] = A[L];                                         // store the index
        else {                                // recursively compute the values
            build(left(p) , L              , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R          );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 * p2;
        }
    }

    int query(int p, int L, int R, int i, int j) {                  // O(log n)
        if (i >  R || j <  L) return 1; // current segment outside query range
        if (L >= i && R <= j) return st[p];               // inside query range
        int p1 = query(left(p) , L            , (L+R) / 2, i, j);
        int p2 = query(right(p), (L+R) / 2 + 1, R        , i, j);
        return p1*p2;
    }          // as as in build routine

    int update_point(int p, int L, int R, int idx, int new_value) {

        int i = idx, j = idx;
        if (i > R || j < L)
            return st[p];
        if (L == i && R == j) {
            A[i] = new_value; // update the underlying array
            return st[p] = new_value; // this index
        }
        int p1, p2;
        p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
        p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

        // return the pition where the overall minimum is
        return st[p] = (p1 * p2);
    }

public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();              // copy content for local usage
        st.assign(4 * n, 0);            // create large enough vector of zeroes
        build(1, 0, n - 1);                                  // recursive build
    }

    int query(int i, int j) {
        return query(1, 0, n - 1, i, j);    // overloading
    }

    int update_point(int idx, int new_value) {
        return update_point(1, 0, n - 1, idx, new_value);
    }
};

int main() {
    int n, q, tmp;
    char op;
    int a,b;
    while(cin >> n >> q) {
        vi vec(n);
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            if(tmp > 0)
                vec[i] = 1;
            else if(tmp < 0)
                vec[i] = -1;
            else
                vec[i] = 0;
        }
        SegmentTree st(vec);
        string ans = "";

        while(q--) {
            cin >> op >> a >> b;
            if(op == 'C') {
                if(b > 0) b = 1;
                else if(b < 0) b = -1;
                st.update_point(a-1, b);
            } else {
                int x = st.query(a-1, b-1);
                if(x>0)
                    ans = ans + '+';
                else if( x < 0)
                    ans = ans + '-';
                else
                    ans = ans + '0';
            }
        }
        cout << ans << endl;
    }
    return 0;
}
