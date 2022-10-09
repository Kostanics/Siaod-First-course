#include <iostream>
using namespace std;

struct node{
    int e;
    node* l, * r;
};
node* tree = NULL;

void push(int x, node** t){
    if ((*t) == NULL){
        (*t) = new node;
        (*t)->e = x;
        (*t)->l = (*t)->r = NULL;
        return;
    }
    if (x > (*t)->e) {
        push(x, &(*t)->r);
    }
    else {
        push(x, &(*t)->l);
    }
}

void print(node* t, int x)
{
    if (t == NULL) {
        return;
    }
    else{
        print(t->l, ++x);
        for (int i = 0; i < x; ++i) {
            cout << "_";
        }
        cout << t->e << endl;
        --x;
    }
    print(t->r, ++x);
}

int main()
{
    int n, e;
    cout << "enter number:";
    cin >> n;
    for (int i = 0; i < n; ++i){
        cout << "enter element:";
        cin >> e;
        push(e, &tree);
    }
    print(tree, 0);
}
