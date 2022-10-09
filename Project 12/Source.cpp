#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
using namespace std;

struct element {
	int num;
	string name;
	string addres;
	element() {
		num = 1 + rand() % 10000000;
		name = "Name:" + to_string(num);
		addres = "Addres:" + to_string(num);
	}
};

class bank {
public:
	element arr[10000];
	int max = 0;
	bank() {
		for (int i = 0; i < 10000; i++) {
			arr[i].num = 0;
			arr[i].name = "";
			arr[i].addres = "";
		}
		max = 0;
	}

	int has(int num) {
		int hash;
		num = num / 10;
		if (num % 2) {
			hash = num / 2;
		}
		else {
			hash = 10000 - num / 2;
		}
		return hash;
	}

	void add(element A) {
		int h = has(A.num);
		int place = 0;
		if (arr[h].name == "") {
			arr[h] = A;
		}
		else {
			for (int i = 1; i < 10000; i++) {
				if (h + i < 10000) {
					if (arr[h + i].name == "") {
						arr[h + i] = A;
						max = i;
						break;
					}
				}
				else {
					if (arr[h + i].name == "") {
						arr[h + i - 10000] = A;
						max = i;
						break;
					}
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < 10000; i++) {
			if (arr[i].name != "") {
				cout << "number: " << i << endl << "id: " << arr[i].num << endl << arr[i].name << endl << arr[i].addres << endl << endl;
			}
		}
	}
};

int main()
{
	srand(time(NULL));
	bank b;
	element el1, el2, el3;
	b.add(el1);
	b.add(el2);
	b.add(el3);
	b.print();
	ofstream f;
	f.open("bank.txt");
	for (int i = 0; i < 10000; i++) {
		if (b.arr[i].name != "") {
			f << "number:" << i << endl << "id:" << b.arr[i].num << endl << b.arr[i].name << endl << b.arr[i].addres << endl << endl;
		}
	}
	f.close();

	ifstream a("bank.txt");
	ofstream out("out.b", ios::out | ios::binary);
	element* ad = b.arr;
	cout << b.arr[0].name << endl << endl;
	string d;
	for (int i = 0; i < 10000; i++) {
		if (ad[i].name != "") {
			out.write((char*)&ad[i], sizeof(element));
		}
	}
	a.close();
	out.close();
	element* ad2 = new element[5];
	ifstream ib("out.b", ios::out | ios::binary);
	for (size_t i = 0; i < 5; i++) {
		ib.read((char*)&ad2[i], sizeof(element));
	}
	ib.close();
}
