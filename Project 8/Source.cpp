#include <iostream> 
#include <stack>
using namespace std;

int main() {
    int n, x;
    stack<int> s;
    cout << "enter height:";
    cin >> n;
    cout << endl;
    cout << "enter point:";
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            s.push(x);
        }
        if (i > 0) {
            if (x > s.top()) {
                s.push(x);
            }
        }
    }
    cout << endl;
    cout << "can see:";
    cout << s.size();
}
