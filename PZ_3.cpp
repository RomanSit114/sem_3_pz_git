#include <iostream>
#include <vector> 
#include <set> 
#include <time.h>
using namespace std;

string GetAlphabet() {
	string alphabet = "";//������� ������ ������ ��� ��������
	for (int i = (int)'a'; i <= (int)'z'; i++) {//����� ����������, �� a �� z
		alphabet = alphabet + (char)i;
	}
	for (int i = (int)'0'; i <= (int)'9'; i++) {//����� ����������, �� 0 �� 9
		alphabet = alphabet + (char)i;
	}
	return alphabet;
}

int hashFunction(string inputString) { // string inputString - ������, �� ������� ������� hash, hashFunction - ���-�������
	int sum = 0, seed = 131;//sum ����� ����� �������� ���-��� ������� ������, seed (������� �����) ����� ��������� ���-�� ��������
	for (int i = 0; i < inputString.length(); i++) {
		sum = sum * seed;//����� ��������� ��������
		sum = sum + (int)inputString[i];  //���� ��� �������� �������������� ���� �� �������
	}
	return sum % 472309/*6252871*/;//��� ����� ������� �� ���������� �����, ������� ����� ��� ���� ����� ��������� ��� ��������
}

int main() {
	string alphabet;
	setlocale(LC_ALL, "ru");
	alphabet = GetAlphabet();//����� "��������"
	cout << alphabet << endl;
	//int lengthString = 3;//������ ����� ������
	int collision = 0;
	string currentString;
	vector <string> stringSet;//���������� ��� ��������� ���� �������, ������� �� �����������, stringSet ����� ������������ ��������, stringSet - ��� ���-�� �������
	vector <int> hashSet;//���������� ��� �������� ��������� �����
	for (int i = 0; i < alphabet.length(); i++) {
		for (int j = 0; j < alphabet.length(); j++) {//alphabet.lenght - ����� ������ ��������
			for (int k = 0; k < alphabet.length(); k++) {
				for (int l = 0; l < alphabet.length(); l++) {
					for (int m = 0; m < alphabet.length(); m++) {
						currentString = (string(1, alphabet[i]) + string(1, alphabet[j]) + string(1, alphabet[k]) + string(1, alphabet[l]) + string(1, alphabet[m]));//���������� ���� ���������� �������, string(1, alphabet[i]) - ��������� ������ char aplphabet [i] � ������ ������ 1
						if (find(hashSet.begin(), hashSet.end(), hashFunction(currentString)) != hashSet.end()) {//���� �� ��� � hashSet, find ���� �������, ��������� ��� ��������� � ���������� ������� find
							collision = collision + 1;
						}


						stringSet.push_back(currentString);

						//i,j,k ������ ��� ����� 3
					 //hashSet.insert(hash<string>{}(stringSet.back()));//inser - �����, ����������� ������� � ���������, back - �����,������� ��������� ������� �� �������
						hashSet.push_back(hashFunction(currentString));//push_back - ��������� ������� � ����� �������, �������� ��� �� currentstring � ������� ������� hashfunction � ��������� ��� � ����� hashset
					}
				}
			}
		}
	}
	/*for (int i = 0; i < stringSet.size(); i++) {
		cout << stringSet[i] << endl; //����� �����
	}*/
	cout << "���������� ��������:  " << collision << endl;//����� ���-�� ��������
	cout << "������� 4" << endl;

	clock_t startTime = clock();
	for (int i = 0; i < stringSet.size(); i++) {//stringSet.size() - ���-�� ��������� � stringSet.size()
		for (int j = i + 1; j < stringSet.size(); j++) {
			stringSet[j] == stringSet[i];//��������� �����
		}
	}
	clock_t endTime = clock();
	cout << "�������� ��������� ����� ��������� �����  " << (double) (endTime - startTime)/ CLOCKS_PER_SEC << endl;//CLOCKS_PER_SEC - ���-�� ������ ���������� � ���

	startTime = clock();
	for (int i = 0; i < hashSet.size(); i++) {//stringSet.size() - ���-�� ��������� � stringSet.size()
		for (int j = i + 1; j < hashSet.size(); j++) {
			hashSet[j] == hashSet[i];//��������� �����
		}
	}
	endTime = clock();
	cout << "�������� ��������� ����� ��������� ���-�����  " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
}

//������� ���������� ���-�������� ���� �� ������ ��� ���