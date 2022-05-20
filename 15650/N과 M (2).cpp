#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> comb;
void Combination(int length, int index) {
	if (length == M) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i <= N; i++) {
		comb[length] = i;
		Combination(length + 1, i + 1);
	}
}
int main() {
	cin >> N >> M;
	comb.resize(M);
	Combination(0,1);
}