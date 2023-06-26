#include<iostream>
#include<Windows.h>
using namespace std;
class Hash_Map {
	int *arr;
	int count = 0;
public:
	Hash_Map() {
		arr = new int[15];
		for (int i = 0; i < 15; i++) {
			arr[i] = -1;
		}
	}
	int Index_No(int index) {
		return (index % 15);
	}
	void Insert(int data) {
		int pos=Index_No(data);
		if (arr[pos] == -1) {
			arr[pos] = data;
		}
		else {
			for (int i = pos; i < 15; i++) {
				if (arr[i] == -1) {
					arr[i] = data;
					return ;
				}
			}
			for (int i = 0; i < pos; i++) {
				if (arr[i] == -1) {
					arr[i] = data;
					return ;
				}
			}
		}
	}
	void Deletion(int key) {
		int pos= Index_No(key);
		if (arr[pos]==key) {
			arr[pos] = -1;
		}
		else {
			for (int i = pos; i < 15; i++) {
				if (arr[i] == key) {
					arr[i] = -1;
					return;
				}
			}
			for (int i = 0; i < pos; i++) {
				if (arr[i] == key) {
					arr[i] = -1;
					return;
				}
			}
		}
	}
	int Search(int key) {
		int pos = Index_No(key);
		if (arr[pos] == key) {
			return pos;
		}
		else {
			for (int i = pos; i < 15; i++) {
				if (arr[i] == key) {
					return i;
				}
			}
			for (int i = 0; i < pos; i++) {
				if (arr[i] == key) {
					return i;
				}
			}
		}
		return 0;
	}
	void Display() {
		cout << "Your Data\n";
		cout << "----------\n";
		for (int i = 0; i < 15; i++) {
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
			a.Deletion(key);
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
