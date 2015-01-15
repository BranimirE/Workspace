#include <cstdio>
#include <set>
#include <vector>

using namespace std;

set<int> st;
set<int>::iterator it;
vector<int> array;
int LIS(int n){
	st.clear();
	int i;
	for(i=0; i<n; i++) {
		st.insert(array[i]);
		it=st.find(array[i]);
		it++;
		if(it!=st.end()) st.erase(it);

	}
	return st.size();
}

int main(){
	int t, n, tmp;
		
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		array.clear();
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			array.push_back(tmp);
		}
		printf("%d\n", n- LIS(n));
	}
	return 0;
}
