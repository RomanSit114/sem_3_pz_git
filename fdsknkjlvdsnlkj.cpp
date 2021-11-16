#include <iostream>
#include <vector>
#include <numeric>//математические функции
using namespace std;

void vectorFunction(int sizeVector1, int sizeVector2) {//sizeVector1 - задаем размерность
	srand(time(NULL));
	vector <int> vector1, vector2, vectorCross;//инициализируем сами вектора, vectorCross - вектор, хранящий пересекающие переменные
	cout << "vector1\n\n";
	for (int i = 0; i < sizeVector1; i++) {//заполнение векотора1 значениями 
		vector1.push_back(rand()%201-100);//push_back - метод,добавляющий число в конец вектора
		cout << vector1[i] << " ";
	}
	cout << endl << endl;

	cout << "vector2\n\n";
	for (int i = 0; i < sizeVector2; i++) {//заполнение векотора1 значениями 
		int temp = rand() % 201 - 100;//temp - переменная, хранящая сгенерированное число
		vector2.push_back(temp);//push_back - метод,добавляющий число в конец вектора
		cout << vector2[i] << " ";
		if (find(vector1.begin(), vector1.end(), temp) != vector1.end()) {//функция find возвращает итератор указывающий на значение, если значение не найдено, то указывает на конец
			vectorCross.push_back(temp);//находим пересекающиеся переменные в двух векторах
		}
	}
	cout << endl;

	double accumulateValue1 = accumulate(vector1.begin(), vector1.end(), 0.0)/sizeVector1;//среднее арифметическое, vector1.begin() - возвращение итератора на первый элемент массива
	//vector2.end() - на последний, 0.0 - первоначальная сумма от которой мы отталкиваемся
	cout << endl << "accumulateValue\n\n" << "accumulateValue1 = " << accumulateValue1 << endl;
	double accumulateValue2 = accumulate(vector2.begin(), vector2.end(), 0.0) / sizeVector2;
	cout << "accumulateValue2 = " << accumulateValue2 << endl;
	cout << endl << "vectorCross" << endl;
	for (int i = 0; i < vectorCross.size(); i++) {
		cout << vectorCross[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "Zadanie 2 vector" << endl << endl;
	vectorFunction(10,20);//выводим векторы
}
