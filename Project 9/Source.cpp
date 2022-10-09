#include "iostream"
using namespace std;

int maxi(int i){
    int max = 0;
    while (i > 1){
        i /= 10;
        max++;
    }
    return max;
}

int siz(int i, int r){
    while (r > 1){
        i /= 10;
        r--;
    }
    return i % 10;
}

void sorty(int** array1, int* array, int r, int n){
    int* arr, i, j, t = 0;
    arr = new int[n];
    for (i = 0; i < n; i++) {
        arr[i] = 0;
    }
    for (i = 0; i < n; i++){
        int a = siz(array[i], r);
        array1[arr[a]][a] = array[i];
        arr[a]++;
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < arr[i]; j++){
            array[t] = array1[j][i];
            t++;
        }
    }
}

int main()
{
    srand(time(NULL));
    int n, s = 0;
    int r, * array, ** array1;
    cout << "enter size: ";
    cin >> n;
    array = new int[n];
    cout << "elements: " << endl;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % n;
        cout << i + 1 << ":" << array[i] << "  ";
    }
    cout << endl;
    array1 = new int* [n];
    for (int i = 0; i < n; i++) {
        array1[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        if (s < maxi(array[i])) {
            s = maxi(array[i]);
        }
    }
    for (r = 1; r <= s; r++) {
        sorty(array1, array, r, n);
    }
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}
