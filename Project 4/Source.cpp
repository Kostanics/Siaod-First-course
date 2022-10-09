#include <iostream>
using namespace std;

void sorty(const int n) {
    int comparisonsCount = 0;
    int x;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
        //cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "Find: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        comparisonsCount++;
        if (arr[i] == x) {
            cout << "position: " << i << endl;
            break;
        }
    }
    cout << "number of comparisons:" << comparisonsCount << endl;
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
