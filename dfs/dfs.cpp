#include <iostream>
#include <sstream>
#include <vector>
#include<queue>
#include<stack>

using namespace std;

void dfs(const vector<vector<int>>& grsm, int start) {//в глубину через стек
	int si = grsm.size();
	vector<bool> v(si, false);
	stack<int> st;
	st.push(start);
	v[start] = true;
	while (!st.empty()) {
		int tek = st.top();
		st.pop();
		cout << tek << " ";
		for (int sos : grsm[tek]) {
			if (!v[sos]) {
				st.push(sos);
				v[sos] = true;
			}
		}
	}
}
