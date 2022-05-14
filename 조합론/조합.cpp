#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int const MAX_LEVEL = 6;
int const P_MAX_LEVEL = 3;
int numbers[50];
int K;
vector<int> comb(MAX_LEVEL);
#pragma region 조합
void Combination(int depth, int index) {
	if (depth == MAX_LEVEL) {
		for (int i = 0; i < MAX_LEVEL; i++) {
			cout << comb[i];
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < K; i++) {
		comb[depth] = numbers[i];
		Combination(depth + 1, i + 1);
	}
}
#pragma endregion
#pragma region 중복조합
void DuplicateCombination(int depth, int index) {
	if (depth == MAX_LEVEL) {
		for (int i = 0; i < MAX_LEVEL; i++) {
			cout << comb[i];
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < K; i++) {
		comb[depth] = numbers[i];
		DuplicateCombination(depth + 1, i);
	}
}
#pragma endregion
#pragma region 순열
void Permutation(int depth) {
	if (depth == P_MAX_LEVEL) {
		for (int i = 0; i < P_MAX_LEVEL; i++) {
			cout << numbers[i];
		}
		cout << "\n";
		return;
	}

	for (int i = depth; i < K; i++) {
		swap(numbers[depth], numbers[i]);
		Permutation(depth + 1);
		swap(numbers[depth], numbers[i]);
	}
}
#pragma endregion
#pragma region 중복순열
void DuplicatePermutation(int depth) {
	if (depth == P_MAX_LEVEL) {
		for (int i = 0; i < P_MAX_LEVEL; i++) {
			cout << comb[i];
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < K; i++) {
		comb[depth] = numbers[i];
		DuplicatePermutation(depth + 1);
	}
}
#pragma endregion
int main() {
	while (true) {
		cin >> K;
		if (K == 0)break;

		for (int i = 0; i < K; i++) {
			cin >> numbers[i];
		}
		Combination(0, 0);
		//Permutation(0);
		cout << "\n";
	}
}