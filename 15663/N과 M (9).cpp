#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int allNumbers[9];
int usingNum [9];
bool flag[9];
void Permutation(int length) {
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << to_string(usingNum[i]) + " ";
		}
		cout << "\n";
		return;
	}
	int prev = -1;
	for (int i = 0; i < N; i++){
		if (!flag[i] && prev != allNumbers[i]) {
			prev = allNumbers[i];
			usingNum[length] = allNumbers[i];
			flag[i] = true;
			Permutation(length + 1);
			flag[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> allNumbers[i];
	}
	sort(allNumbers, allNumbers + N);
	Permutation(0);
}