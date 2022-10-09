#include <iostream>
#include <fstream>
using namespace std;

int position(const char* x, const char* t, int n)
{
	int j, len1, len2;
	for (len1 = 0; t[len1]; len1++);
	for (len2 = 0; x[len2]; len2++);
	for (int i = 0; i <= len2 - len1; i++){
		for (j = 0; x[i + j] == t[j]; j++);
		if (j - len1 == 1 && i == len2 - len1 && !(n - 1)) { 
			return i; 
		}
		if (j == len1) {
			if (n - 1) {
				n--;
			}
			else {
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	string a;
	char b[10000];
	ifstream f("C:\\Users\\USER\\Desktop\\txt-file-B.txt");
	while (!f.eof()){
		f.getline(b, sizeof(b));
		cout << b << endl;
	}
	cout << endl;
	cout << "enter string:";
	cin >> a;
	const char* x = b;
	const char* t = a.c_str();
	int n = 0;
	cout << endl;
	cout << "position string:";
	for (int i = 1; n != -1; i++){
		n = position(x, t, i);
		if (n >= 0) {
			cout << n << " ";
		}
	}
	cout << endl;
}
