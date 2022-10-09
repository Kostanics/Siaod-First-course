#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;
map<char, int> f;

struct Minh {
    char data;
    int f;
    Minh* left, * right; 
    Minh(char data, int f) {
        left = right = NULL;
        this->data = data;
        this->f = f;
    }
};

struct comp {
    bool operator()(Minh* l, Minh* r){
        return (l->f > r->f);
    }
};

void print(struct Minh* root, string str) {
    if (!root) {
        return;
    }
    if (root->data != '*') {
        cout << root->data << ": " << str << endl;
    }
    print(root->left, str + "0");
    print(root->right, str + "1");
}

void store(struct Minh* root, string str) {
    if (root == NULL) {
        return;
    }
    if (root->data != '*') {
        codes[root->data] = str;
    }
    store(root->left, str + "0");
    store(root->right, str + "1");
}

priority_queue<Minh*, vector<Minh*>, comp> minh;

void Huff(int size) {
    struct Minh* left, * right, * top;
    for (map<char, int>::iterator v = f.begin(); v != f.end(); v++) {
        minh.push(new Minh(v->first, v->second));
    }
    while (minh.size() != 1) {
        left = minh.top();
        minh.pop();
        right = minh.top();
        minh.pop();
        top = new Minh('*', left->f + right->f);
        top->left = left;
        top->right = right;
        minh.push(top);
    }
    store(minh.top(), "");
}

void freq(string str, int n) {
    for (int i = 0; i < str.size(); i++)
        f[str[i]]++;
}

string decodf(struct Minh* root, string s) {
    string as = "";
    struct Minh* c = root;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            c = c->left;
        }
        else {
            c = c->right;
        }
        if (c->left == NULL and c->right == NULL){
            as += c->data;
            c = root;
        }
    }
    return as;
}
int main() {
    string s;
    cout << "enter string: ";
    cin >> s;
    string cod, decod;
    freq(s, s.length());
    Huff(s.length());
    cout << "code sign: " << endl;
    for (auto v = codes.begin(); v != codes.end(); v++) {
        cout << v->first << ' ' << v->second << endl;
    }
    for (auto i : s) {
        cod += codes[i];
    }
    cout << "code string: " << cod << endl;
    decod = decodf(minh.top(), cod);
    cout << "decode string: " << decod << endl;
}
