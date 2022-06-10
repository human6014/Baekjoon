#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int>numbers;
vector<int>answers;
void DupleCombination(int index, int depth) {
	if (depth == M) {
		for (int i = 0; i < answers.size(); i++) {
			cout << answers[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i < numbers.size(); i++) {
		answers[depth] = numbers[i];
		DupleCombination(i, depth + 1);
	}
}
int main() {
	cin >> N >> M;
	numbers.resize(N);
	answers.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());
	DupleCombination(0,0);
}