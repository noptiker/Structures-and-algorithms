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

int main(){
	ios::sync_with_stdio(0);//просто 
	cin.tie(0);    
	cout.tie(0); 
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Сколько вершин: ";
	cin >> n;
	cin.ignore();//ввод списка смежности
	vector<vector<int>> grsm(n);//список смежности
	cout << '\n' << "Список смежности:";
	string s;
	for (int i = 0; i < n; i++) {//ввели список смежности
		cout << '\n' << i << ": ";
		getline(cin, s);
		istringstream iss(s);
		int nb;
		while (iss >> nb) {//разбиваем через пробел через sstream
			grsm[i].push_back(nb);
		}
	}

}
