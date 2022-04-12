#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Num, Sub = 0;
	cin >> Num;
	int* arr = new int[Num];
	for (int i = 0; i < Num; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + Num);
	for (int i = 0; i < Num; i++) {
		for (int j = 0; j <= i; j++) {
			Sub += arr[j];
		}
	}
	cout << Sub;
}