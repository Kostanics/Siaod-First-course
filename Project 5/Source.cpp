#include <iostream>
using namespace std;

void sorty(const int n) {
    int x;
    int position = 0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = rand() % n; 
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "Find: "; 
    cin >> x;
    if (arr[n - 1] != x){
        arr[n - 1] = x;
        for (; arr[position] != x; position++);
        position++;
    }
    else{
        cout << n;
    }
    cout << "position: " << position;
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