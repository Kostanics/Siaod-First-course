#include <iostream>
using namespace std;

int OSRS(int arr[], int x, int n){
	int c;
	int min = INT_MAX;
	if (x == n) {
		return 0;
	}
	for (int i = x; i < n; i++){
		c = OSRS(arr, x, i) + OSRS(arr, i + 1, n) + arr[x - 1] * arr[i] * arr[n];
		if (c < min) {
			min = c;
		}
	}
	return min;
}

int main(){
	int arr[7] = { 5, 10, 3, 12, 5, 50, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "best way to place parentheses: "<< OSRS(arr, 1, n - 1);
}
