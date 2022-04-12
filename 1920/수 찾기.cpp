#include <iostream>
#include <algorithm>
using namespace std;

int num1, num2;

void find(int arr1[], int arr2) {
	cout.tie(NULL);
	int start = 0, end = num1 - 1;
	while (end >= start) {
		int mid = (start + end) / 2;
		if (arr1[mid] == arr2) {
			cout << "1\n";
			break;
		}
		else if (arr1[mid] > arr2) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
		if (end < start) {
			cout << "0\n";
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> num1;
	int* arr1 = new int[num1];
	for (int i = 0; i < num1; i++) {
		cin >> arr1[i];
	}
	sort(arr1, arr1 + num1);
	cin >> num2;
	int* arr2 = new int[num2];
	for (int i = 0; i < num2; i++) {
		cin >> arr2[i];
		find(arr1, arr2[i]);
	}

}