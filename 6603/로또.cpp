#include <iostream>
#include <vector>
using namespace std;

int const MAX_LEVEL = 6;
int numbers[50];
int comb[6];
int K;


void Combination(int depth, int index) {
	if (depth == MAX_LEVEL) {
		for (int i = 0; i < MAX_LEVEL; i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < K; i++) {
		comb[depth] = numbers[i];
		Combination(depth + 1, i + 1);
	}
}
int main() {
	while (true) {
		cin >> K;
		if (K == 0)break;

		for (int i = 0; i < K; i++) {
			cin >> numbers[i];
		}
		Combination(0,0);
		cout << "\n";
	}
}

/*
7 1 2 3 4 5 6 7

1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7
*/