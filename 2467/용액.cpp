#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> waters;
int main() {
	cin >> N;
	waters.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> waters[i];
	}

	int answer1;
	int answer2;
	int left = 0;
	int right = waters.size() - 1;
	int differ = 2000000001;
	while (left < right) {
		if (abs(differ) > abs(waters[left] + waters[right])) {
			differ = waters[left] + waters[right];
			answer1 = waters[left];
			answer2 = waters[right];
		}
		if (abs(waters[left + 1] + waters[right]) > abs(waters[left] + waters[right - 1])) right--;
		else left++;
	}
	cout << answer1 << " " << answer2;
}