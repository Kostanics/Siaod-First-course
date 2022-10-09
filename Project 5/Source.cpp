#include <iostream>
#include <algorithm>
using namespace std;

void sorty(const int n) {
    int comparisonsCount = 0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
        //cout << arr[i] << "  ";
    }
    cout << endl;
    //cout << "sort:";
    sort(arr, arr + n);
    cout << endl;
    for (int i = 0; i < n; i++) {
        //cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "enter key: ";
    int key;
    cin >> key;
    int x = 0;
    int p = n;
    int m;
    while (x < p) {
        m = (x + p) / 2;
        if (arr[m] > key) {
            comparisonsCount++;
            p = m;
        }
        else {
            x = m + 1;
        }
    }
    p--;
    if (arr[p] == key) {
        cout << "position: " << p << endl << "number of comparisons" << comparisonsCount << endl;
    }
    else {
        cout << "not found";
    }
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "For 100 elements:" << endl;
    sorty(n = 100);
    system("pause");

    cout << "For 1000 elements:" << endl;
    sorty(n = 1000);
    system("pause");

    cout << "For 10000 elements:" << endl;
    sorty(n = 10000);
    system("pause");

    cout << "For 100000 elements:" << endl;
    sorty(n = 100000);
    system("pause");

    cout << "For 1000000 elements:" << endl;
    sorty(n = 1000000);
    system("pause");
}
