#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> money;
int main() {
	cin >> N >> K;
	int answer = 0;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (K >= num) money.push_back(num);
	}

	for (int i = money.size() - 1; i >= 0; i--) {
		if (K / money[i] >= 0) {
			answer += K / money[i];
			K = K % money[i];
		}
		if (K == 0) break;
	}
	cout << answer;
}