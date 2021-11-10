#include <iostream>
#include <vector> 
#include <set> 
#include <time.h>
using namespace std;

string GetAlphabet() {
	string alphabet = "";//заводим пустую строку для алфавита
	for (int i = (int)'a'; i <= (int)'z'; i++) {//явное приведение, от a до z
		alphabet = alphabet + (char)i;
	}
	for (int i = (int)'0'; i <= (int)'9'; i++) {//явное приведение, от 0 до 9
		alphabet = alphabet + (char)i;
	}
	return alphabet;
}

int hashFunction(string inputString) { // string inputString - строка, от которой берется hash, hashFunction - хэш-функция
	int sum = 0, seed = 131;//sum нужна чтобы получить хэш-код входной строки, seed (простое число) чтобы уменьшить кол-во коллизий
	for (int i = 0; i < inputString.length(); i++) {
		sum = sum * seed;//чтобы уменьшить коллизии
		sum = sum + (int)inputString[i];  //цикл для подсчета промежуточного хэша от строчек
	}
	return sum % 472309/*6252871*/;//это число зависит от количества строк, простое число для того чтобы увеличить наш диапазон
}

int main() {
	string alphabet;
	setlocale(LC_ALL, "ru");
	alphabet = GetAlphabet();//вывод "алфавита"
	cout << alphabet << endl;
	//int lengthString = 3;//размер длины строки
	int collision = 0;
	string currentString;
	vector <string> stringSet;//переменная для множества всех строчек, которые мы сгененируем, stringSet будет динамическим массивом, stringSet - это кол-во строчек
	vector <int> hashSet;//переменная для хранения множества хэшей
	for (int i = 0; i < alphabet.length(); i++) {
		for (int j = 0; j < alphabet.length(); j++) {//alphabet.lenght - длина нашего алфавита
			for (int k = 0; k < alphabet.length(); k++) {
				for (int l = 0; l < alphabet.length(); l++) {
					for (int m = 0; m < alphabet.length(); m++) {
						currentString = (string(1, alphabet[i]) + string(1, alphabet[j]) + string(1, alphabet[k]) + string(1, alphabet[l]) + string(1, alphabet[m]));//генерирует одну уникальную строчку, string(1, alphabet[i]) - переводит символ char aplphabet [i] в строку длиной 1
						if (find(hashSet.begin(), hashSet.end(), hashFunction(currentString)) != hashSet.end()) {//есть ли хэш в hashSet, find ищет элемент, прочитать про итераторы и посмотреть функцию find
							collision = collision + 1;
						}


						stringSet.push_back(currentString);

						//i,j,k потому что длина 3
					 //hashSet.insert(hash<string>{}(stringSet.back()));//inser - метод, вставляющий элемент в множество, back - метод,берущий последний элемент из массива
						hashSet.push_back(hashFunction(currentString));//push_back - вставляет элемент в конец вектора, получаем хэш от currentstring с помощью функции hashfunction и вставляем его в конец hashset
					}
				}
			}
		}
	}
	/*for (int i = 0; i < stringSet.size(); i++) {
		cout << stringSet[i] << endl; //вывод строк
	}*/
	cout << "Количество коллизий:  " << collision << endl;//вывод кол-ва коллизий
	cout << "Задание 4" << endl;

	clock_t startTime = clock();
	for (int i = 0; i < stringSet.size(); i++) {//stringSet.size() - кол-во элементов в stringSet.size()
		for (int j = i + 1; j < stringSet.size(); j++) {
			stringSet[j] == stringSet[i];//сравнение строк
		}
	}
	clock_t endTime = clock();
	cout << "Скорость сравнения через сравнение строк  " << (double) (endTime - startTime)/ CLOCKS_PER_SEC << endl;//CLOCKS_PER_SEC - кол-во тактов процессора в сек

	startTime = clock();
	for (int i = 0; i < hashSet.size(); i++) {//stringSet.size() - кол-во элементов в stringSet.size()
		for (int j = i + 1; j < hashSet.size(); j++) {
			hashSet[j] == hashSet[i];//сравнение хэшей
		}
	}
	endTime = clock();
	cout << "Скорость сравнения через сравнение хэш-кодов  " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
}

//функция вычисления хэш-значений сами ли писали или нет