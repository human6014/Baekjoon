#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
int minDiv = 2000000001;
vector<int> numbers;
int answer1, answer2;
bool sorting(int a, int b) {
	if (abs(a) > abs(b))return true;
	return false;
}
int main() {
	cin >> N;
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end(), sorting);

	for (int i = 0; i < N - 1; i++) {
		if (abs(minDiv) > abs(numbers[i] + numbers[i + 1])) {
			answer1 = numbers[i];
			answer2 = numbers[i + 1];
			minDiv = numbers[i] + numbers[i + 1];
		}
	}
	if (answer1 > answer2)cout << answer2 << "\n" << answer1;
	else cout << answer1 << "\n" << answer2;
}