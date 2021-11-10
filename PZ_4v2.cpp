#include <iostream>
#include <map>

using namespace std;
setlocale (LC_ALL, "ru");
void mapFunction(string inputString) {
	map<string, int> stringCounter;
	string currentWord;
	int firstSpace = -1;
	for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == ' ' or inputString.length()-1 == i) {  
			if (inputString.length() - 1 == i) {
				i = i + 1;
			}
			currentWord = inputString.substr(firstSpace+1, i - firstSpace-1);
			auto it =  stringCounter.find(currentWord);
			firstSpace = i;
			if (it == stringCounter.end()) {
				stringCounter.emplace(currentWord, 1);
			}
			else {
				it->second = it->second + 1;
			}
		}
	}
	auto it = stringCounter.find("");
	if (it != stringCounter.end())
	{
		stringCounter.erase(it); 
	}
	for (auto element : stringCounter) {
		cout << element.first << " -> " << element.second;
		cout << endl;
	}
}

int main() {
	cout << "Задание 1 map" << endl << endl;
	mapFunction("hello        world    hello hello world");
}