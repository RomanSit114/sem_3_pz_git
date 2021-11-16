#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void vectorFunction(int sizeVector1, int sizeVector2) {
	srand(time(NULL));
	vector <int> vector1, vector2, vectorCross;
	cout << "vector1\n\n";
	for (int i = 0; i < sizeVector1; i++) {
		vector1.push_back(rand()%201-100);
		cout << vector1[i] << " ";
	}
	cout << endl << endl;

	cout << "vector2\n\n";
	for (int i = 0; i < sizeVector2; i++) { 
		int temp = rand() % 201 - 100;
		vector2.push_back(temp);
		cout << vector2[i] << " ";
		if (find(vector1.begin(), vector1.end(), temp) != vector1.end()) {
			vectorCross.push_back(temp);
		}
	}
	cout << endl;

	double accumulateValue1 = accumulate(vector1.begin(), vector1.end(), 0.0)/sizeVector1;
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
	vectorFunction(10,20);
}
