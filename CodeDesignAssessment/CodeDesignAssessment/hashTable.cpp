#include <iostream>
#include <list>
#include <cstring>
#include <string>
using namespace std;


//hashing phone# and name, example: 102, James
class hashTable
{
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];


public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();

};

bool hashTable::isEmpty() const
{
	int sum{};

	for (int i{}; i < hashGroups; i++)
	{
		sum += table[i].size();
	}

	if (!sum)
	{
		return true;
	}
	return false;
}

int hashTable::hashFunction(int key)
{
	return key % hashGroups; //Key 102, function returns 2
}

void hashTable::insertItem(int key, string value)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr->second = value;
			cout << "Key exists, value replaced." << endl;
			break;
		
		}
	}

	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}

	return;
}

void hashTable::removeItem(int key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "Item removed." << endl;
			break;

		}
	}

	if (!keyExists)
	{
		cout << "Item missing." << endl;
	}

	return;
}

void hashTable::printTable()
{
	for (int i{}; i < hashGroups; i++)
	{
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++)
		{
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}

	return;
}

int main()
{
	hashTable HT;

	if (HT.isEmpty())
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Check the code!" << endl;
	}

	HT.insertItem(303, "Will");
	HT.insertItem(165, "Oswald");
	HT.insertItem(849, "Wendy");
	HT.insertItem(231, "Igor");
	HT.insertItem(468, "Sue");
	HT.insertItem(623, "Usain");
	HT.insertItem(999, "Carl");
	HT.insertItem(667, "Karly");
	HT.insertItem(667, "Karly");

	HT.printTable();

	HT.removeItem(849);
	HT.removeItem(333);

	if (HT.isEmpty())
	{
		cout << "Check the code!" << endl;
	}
	else
	{
		cout << "Correct!" << endl;
	}

	getchar();

	return 0;

}