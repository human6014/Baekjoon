#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<int> numbers;
bool sorting(int a, int b) {
	return (to_string(a) + to_string(b) > to_string(b) + to_string(a));
}
int main() {
	cin >> N;
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end(), sorting);

	for (int i = 0; i < N; i++) {
		cout << numbers[i];
		if (numbers[0] == 0) break;
	}
}