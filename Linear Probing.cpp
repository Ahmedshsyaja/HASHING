#include<iostream>
#include<Windows.h>
using namespace std;
class Hash_Map {
	int *arr;
	int count = 0;
public:
	Hash_Map() {
		arr = new int[10];
		for (int i = 0; i < 10; i++) {
			arr[i] = -1;
		}
	}
	int Index_No(int index) {
		int los = 1;
		int pos = index % 10;
		if (arr[pos] == -1)
		{
			return pos;
		}
		else {
			pos = 1;
			int nex = 0;
			for (int i = 0; i < 10; i++) {
				nex = pos * pos;
				los = (index+nex)% 10;
				pos = pos + 1;
				if (pos == 10) {
					return -1;
				}
				if (arr[los] == -1) {
					return los;
				}
			}
		}
		return -1;
	}
	void Insert(int data) {
		int pos=Index_No(data);
		if (pos!=-1) {
			arr[pos] = data;
		}
	}
	int Search(int key) {
		int los = 1;
		int pos = key % 10;
		if (arr[pos] == key)
		{
			return pos;
		}
		else {
			pos = 1;
			int nex = 0;
			for (int i = 0; i < 10; i++) {
				nex = pos * pos;
				los = (key + nex) % 10;
				pos = pos + 1;
				if (pos == 10) {
					return -1;
				}
				if (arr[los] == key) {
					return los;
				}
			}
		}
		return -1;
	}
	int Delete(int key) {
		int los = 1;
		int pos = key % 10;
		if (arr[pos] == key)
		{
			arr[pos] = -1;
		}
		else {
			pos = 1;
			int nex = 0;
			for (int i = 0; i < 10; i++) {
				nex = pos * pos;
				los = (key + nex) % 10;
				pos = pos + 1;
				if (pos == 10) {
					return -1;
				}
				if (arr[los] == key) {
					arr[los] = -1;
				}
			}
		}
		return -1;
	}
	void Display() {
		cout << "Your Data\n";
		cout << "----------\n";
		for (int i = 0; i < 10; i++) {
			cout << arr[i] << " ";
		}
	}
};
int main() {
	Hash_Map a;
	int b = 0;
	while (true) {
		system("cls");
		cout << "1 Insert\n";
		cout << "2 Delete\n";
		cout << "3 Search\n";
		cout << "4 Display\n";
		int data;
		cin >> data;
		if (data == 1) {
			system("cls");
			int key;
			cin >> key;
			a.Insert(key);
		}
		if (data == 2) {
			system("cls");
			int key;
			cout << "Enter Key\n";
			cin >> key;
			a.Delete(key);
		}
		if (data == 3) {
			int key;
			cout << "Enter Key\n";
			cin >> key;
			if (a.Search(key) != 0) {
				cout << "Key Found At Index No\n";
				cout << a.Search(key) << "\n";
			}
			Sleep(2000);
		}
		if (data == 4) {
			a.Display();
			Sleep(2000);
		}
	}
	a.Display();
}
