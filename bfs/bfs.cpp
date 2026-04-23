#include <iostream>
#include <sstream>
#include <vector>
#include<queue>
#include<stack>

using namespace std;
 
void bfs(vector<vector<int>> &grsm, int start) {//в ширину через очередь
	int si = grsm.size();
	vector<bool> v(si, false);
	queue<int> oh;
	oh.push(start);
	v[start] = true;
	while (!oh.empty()) {
		int tek = oh.front();
		oh.pop();
		cout << tek << " ";
		for (int sos : grsm[tek]) {
			if (!v[sos]) {
				v[sos] = true;
				oh.push(sos);
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
