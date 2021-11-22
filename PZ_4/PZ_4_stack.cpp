#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stack>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Задание 3 stack\n\nВведите кол-во узлов:\n";
	int N = 0;
	cin >> N;
	vector <vector<int>> Nodes(N); 
	string stringValue;
	getline(cin, stringValue);
	for (int i = 0; i < N; i++) {
		getline(cin, stringValue);
		for (int j = 0; j < N; j++) {
			Nodes[i].push_back(0);
		}
		istringstream stringNum(stringValue);
		int connectNodes;//для считывания связи между узлами

		while (stringNum >> connectNodes) {
			if (connectNodes != 0) {
				Nodes[i][connectNodes - 1] = 1;
			}
		}
	}
	cout << endl;
	cout << "Выводим таблицу связей " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Nodes[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	vector <vector<int>> result(N);
	stack <int> x;
	for (int i = 0; i < N; i++) {
		set <int> resultOneNode = {};

		for (int j = 0; j < N; j++)
		{
			result[i].push_back(0); 
		}

		x.push(i);
		while (!x.empty()) {
			int temp = x.top();
			x.pop();
			resultOneNode.insert(temp);
			for (int j = 0; j < N; j++) {
				if (Nodes[temp][j] == 1 && resultOneNode.find(j) == resultOneNode.end()) {
					x.push(j);
				}
			}
		}
		for (auto it = resultOneNode.begin(); it != resultOneNode.end(); it++)
		{
			result[i][*it] = 1; 
		}
	}

	cout << "Вывод матрицы достижимости" << endl;
	for (auto el : result)
	{
		for (auto em : el)
		{
			cout << em << " ";
		}
		cout << endl;
	}
}
