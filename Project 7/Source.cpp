#include <iostream>
#include <vector>
#include <locale.h>
#include <algorithm>
using namespace std;

int main() {
    vector <char> list(0, 0);
    vector <char> L1(0, 0);
    vector <char> L2(0, 0);
    char s1 = ' ', s2 = ' ';
    cout << "enter for L1, to end enter '*' " << ' ' << endl;
    while (cin >> s1) {
        L1.push_back(s1);
        if (s1 == '*') {
            L1.pop_back();
            break;
        }
    }
    cout << endl;
    cout << "L1:" << ' ';
    for (unsigned int i = 0; i < L1.size(); ++i) {
        cout << L1[i] << ' ';
    }
    cout << endl;
    cout << "enter for L2, to end enter '*' " << endl;
    while (cin >> s2) {
        L2.push_back(s2);
        if (s2 == '*') {
            L2.pop_back();
            break;
        }
    }
    cout << endl;
    cout << "L2:" << ' ';
    for (unsigned int i = 0; i < L2.size(); ++i) {
        cout << L2[i] << ' ';
    }
    cout << endl;
    for (unsigned int i = 0; i < L1.size(); ++i) {
        for (unsigned int j = 0; j < L2.size(); ++j) {
            if (L2[j] == L1[i]) {
               list.push_back(L1[i]);
            }
        }
    }
    cout << endl;
    sort(list.begin(), list.end());
    vector<char>::iterator t;
    t = unique(list.begin(), list.end());
    list.resize(t - list.begin());
    if (list.size() > 0) {
        cout << "coincidence:";
        for (unsigned int i = 0; i < list.size(); ++i) {
            cout << list[i] << ' ';
        }
        cout << endl;
    }
    else {
        cout << "not coincidence" << ' ' << endl;
    }
    cout << endl << endl;
    L1.clear();
    L2.clear();
    list.clear();
}
