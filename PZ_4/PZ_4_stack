#include <iostream>
#include <vector>
#include <string>//чтобы работать со строками
#include <set>//для хранения открытых узлов(через которые прошли)
#include <sstream>//работа со строками, чтобы взять данные с cout
#include <stack>//работа со stack, хранение нераскрытых вершин
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Задание 3 stack\n\nВведите кол-во узлов:\n";
	int N = 0;
	cin >> N;
	vector <vector<int>> Nodes(N); //двумерный вектор для хранения узлов
	string stringValue;//будем хранить введенные числа
	getline(cin, stringValue);
	for (int i = 0; i < N; i++) {//Для считывания данных с каждого узла
		getline(cin, stringValue);//считывание перемнных из консоли в stringValue
		for (int j = 0; j < N; j++) {//для обнуления вектора
			Nodes[i].push_back(0);
		}
		istringstream stringNum(stringValue);//из строки в числа
		int connectNodes;//для считывания связи между узлами
		cout << endl;  
		while (stringNum >> connectNodes) {//для того, чтобы считать connectNodes из stringNum
			cout << connectNodes;
			cout << " ";
			if (connectNodes != 0) {
				Nodes[i][connectNodes - 1] = 1;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Nodes[i][j] << " ";
		}
		cout << endl;
	}
	vector <vector<int>> results;
	set <int> resultOneNode;
	stack <int> x;
	for (int i = 0; i < N; i++) {
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
	}
}
