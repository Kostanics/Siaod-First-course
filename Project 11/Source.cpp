#include <iostream>
#include <list>
using namespace std;

class Has {
    int c;
    list<int>* product;
public:
    Has(int V);
    void in(int key, int data);
    void dell(int key);

    int check(int n){
        int i;
        if (n == 0 || n == 1){
            return 0;
        }
        for (i = 2; i < n / 2; i++){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    }

    int get(int n){
        if (n % 2 == 0){
            n++;
        }
        while (!check(n)){
            n += 2;
        }
        return n;
    }

    int hf(int key){
        return (key % c);
    }
    void print();
};

Has::Has(int x){
    int size = get(x);
    this->c = size;
    product = new list<int>[c];
}

void Has::in(int key, int data){
    int ind = hf(key);
    product[ind].push_back(data);
}

void Has::dell(int key){
    int ind = hf(key);
    list<int>::iterator i;
    for (i = product[ind].begin(); i != product[ind].end(); i++){
        if (*i == key) {
            break;
        }
    }

    if (i != product[ind].end()) {
        product[ind].erase(i);
    }
}

void Has::print(){
    for (int i = 0; i < c; i++){
        cout << "product:" << i;
        for (auto x : product[i]) {
            cout << "  code:" << x;
        }
        cout << endl;
    }
}

int main(){
    int key[] = { 5, 3, 4, 6, 7, 9, 8, 2, 1, 10 };
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(key) / sizeof(key[0]);
    Has h(n);
    for (int i = 0; i < n; i++) {
        h.in(key[i], data[i]);
    }
    h.dell(20);
    h.print();
}
