#include <iostream>
#include <list>
#include <string>
#include <set>
#include <sstream>
#include <stack>

using namespace std;

template <typename T>
class List : public list<pair<T, int>>
{
public:

	void insertInEnd(const T& value)
	{
		this->push_back({ value, 0 });
	}

	void insertInFront(const T& value)
	{
		this->push_front({ value, 0 });
	}

	void popFront() 
	{
		this->pop_front();
	}

	void popEnd()
	{
		this->pop_back();
	}

	T getByIndex(int index)
	{
		(*(next(this->begin(), index))).second++;
		T value = (*(next(this->begin(), index))).first;
		this->SortPrior((next(this->begin(), index)), this->begin());
		return value;
	}

	void SortPrior(list<pair<T, int>>::iterator current, list<pair<T, int>>::iterator begin)
	{
		pair<T, int> prioritet_current;
		pair<T, int> prioritet_next;
		while (current != begin)
		{
			prioritet_current = *current;
			prioritet_next = *(next (current, - 1));
			if (prioritet_current.second > prioritet_next.second)
			{
				*(next(current, - 1)) = prioritet_current;
				*current = prioritet_next;
			}
			else
			{
				return;
			}
			next(current, -1);
		}
	}
};
int main() {
	setlocale(LC_ALL, "ru");
	cout << "Задание 5" << endl;
	List <int> li;
	li.insertInEnd(3);
	li.insertInEnd(1);
	li.insertInEnd(15);

	cout << li.getByIndex(1) << endl;
	cout << li.getByIndex(2) << endl;
	cout << li.getByIndex(0) << endl;
	cout << li.getByIndex(1) << endl;
	cout << li.getByIndex(1) << endl;
	cout << li.getByIndex(0) << endl;
	cout << li.getByIndex(2) << endl;
	cout << li.getByIndex(2) << endl;
	cout << li.getByIndex(2) << endl;
	cout << li.getByIndex(1) << endl;
	cout << li.getByIndex(1) << endl;
	cout << li.getByIndex(0) << endl;

	li.popFront();
	li.popEnd();
	cout << "Кол-во символов после удаления одного спереди и одного с конца\n" <<li.size() << endl;
}
