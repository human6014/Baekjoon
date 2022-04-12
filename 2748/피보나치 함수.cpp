#include <iostream>
#include <vector>

using namespace std;
int arr[41];

int fibo(int n) {
	if (n <= 2) {
		if (n == 0) return arr[n] = 0;
		return arr[n] = 1;
	}
	if (arr[n] == 0) {
		return arr[n] = fibo(n - 1) + fibo(n - 2);
	}
	return arr[n];
}
int main() {
	int T;
	vector<int> testCase;
	cin >> T;
	testCase.resize(T);
	for (int i = 0; i < T; i++) cin >> testCase[i];
	for (int i = 0; i < T; i++) {
		cout << fibo(testCase[i]-1) << " " << fibo(testCase[i]) << "\n";
	}
}