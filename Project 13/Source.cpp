#include <iostream>

using namespace std;

void main() {
    srand(time(NULL));
    const int a = 4;
    int mass[a][a];
    int d;
    cout << "1=manual input 2=auto" << endl;
    cin >> d;
    switch (d)
    {
    case 1:
    {
        for(int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                cout << "Введите графы a[" << i << "][" << j << "] ";
                cin >> mass[i][j];
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                mass[i][j]=rand() % 10;
            }
        }
        break;
    }
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int n = 7;
    bool* pr = new bool[n];
    memset(pr, false, sizeof(bool) * n);
    pr[0] = true;
    for (int l = 0; l < n - 1; l++) {
        int minx = -1, miny = -1;
        for (int i = 0; i < n; i++) {
            if (pr[i]) {
                for (int j = 0; j < n; j++) {
                    if (!pr[j] && mass[i][j] > 0 && (miny == -1 || mass[i][j] < mass[miny][minx])) {
                        miny = i, minx = j;
                    }
                }
            }
        }
        pr[minx] = true;
        cout << miny << ": " << minx << endl;
    }
}
