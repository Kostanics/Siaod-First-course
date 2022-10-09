#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double delta;
	cout << "enter delta: ";
	cin >> delta;
	double x1 = 0, x2 = 0;
	while (x1 + x2 <= 2 && x1 >= 0 && x2 >= 0) {
		if (-2 * x1 - 2 * x2 <= -10) {
			cout << "-2x1 - 2x2 <= -10 = true; x1 = " << x1 << ", x2 = " << x2 << "  task solved" << endl;
			return 0;
		}
		else if (delta > 0.001) {
			cout << "-2x1 - 2x2 <= -10 = false; x1 = " << x1 << ", x2 = " << x2 << endl;
		}
		x1 += delta;
		x2 += delta;
	}
	cout << "the task is unsolvable";
}